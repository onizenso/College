.data

default_msg:
    .asciiz "no cmdline args passed\n"
errmsg:
    .asciiz "\nspim -f 80.s <string>\n\n"
newline:
    .asciiz "\n"

.text
.globl main

.ent main
main: 
    move $s0, $a0           # move number of cmd line args to $s0
    move $s1, $a1           # move base addy of cmd line arg to $s1
    move $s2, $zero         # zero out remaining storage registers
    move $s3, $zero         # not used yet, but a precautionary measure
    move $s4, $zero       
    move $s5, $zero       
    li   $t0, 1          
    beq  $s0, $t0, default  # jump to default if no cmdline args
    move $s3, $s0           # use $s3 as arg counter
    move $s4, $s1           # use $s4 as arg index 
    
    addi  $sp, $sp, -32   # stack frame is 32 bytes long
    sw    $ra, 20($sp)    # save return address
    sw    $fp, 16($sp)    # save old frame pointer
    sw    $a0, 4($sp)     # save original count
    addi  $fp, $sp, 28    # set up frame pointer. Skips the padding

    # account for the program name being the first argument
    addi $s3, $s3, -1       # decrement argument counter
    addi $s4, $s4, 4        # increment argument index
    j    cmdline            # print error cmdline args passed

cmdline:
    #load cmdline arg and make syscall to print string
    lw   $a0, ($s4)         # load cmdline string into $a0
    li   $v0, 4             # load print_string syscall
    syscall
    li   $a0, 10            # load newline ascii into $a0
    li   $v0, 11            # load print_char syscall
    syscall
    j    setup 

default:
    la   $a0, default_msg   # load default_msg in $a0
    li   $v0, 4             # load print_string syscall
    syscall
    move $t0, $a0           # send default_msg as parse string to parse
    li   $s5, 1             # use as boolean for default in parse
    j    parse

setup: 
    lw   $s2, ($s4)         # load cmdline arg base addy into $s2
    move $t0, $s2           # $t0 is parse counter, start array at base addy
    li   $t3, 0             # use $t3 to store even byte count, init 0
    li   $t4, 0             # use $t4 to store byte index, init 0

parse: 
    lb   $t1, ($t0)         # load byte at $t0 into $t1
    beq  $t1, $zero, result # break parse when $t1 is NULL, end of string
    addi $t4, 1             # increment index by one
    li   $t5, 2             # load 2 in $t5
    divu $t4, $t5           # check for parity of byte index
    mfhi $t6                # load the modulo result into $t6 
    jal  parity
    move $a0, $t1           # load char into $a0
    li   $v0, 11            # load print_char syscall
    syscall
    li   $a0, 32            # load space ascii into $a0
    li   $v0, 11            # load print_char syscall          
    syscall
    addi $t0, 1             # set $t0 to addy of next byte
    j    parse

parity:
    beqz $t6, even          # break to increment even index 
    jr   $ra                # return to parse at one instruction past jump 
even:
    addi $t3, 1             # increment even count
    jr   $ra                # return to parse at one instruction past jump

result:
    li   $a0, 10            # load newline ascii into $a0  
    li   $v0, 11            # load print_char syscall          
    syscall
    move $a0, $t3           # load count of even characters into $a0
    li   $v0, 1             # load print_int syscall
    syscall
    li   $a0, 10            # load newline ascii into $a0  
    li   $v0, 11            # load print_char syscall          
    syscall
    bnez $s5, exit          # jump to exit if default boolean is set
    la   $a0, ($s4)         # load current string into $a0 to pass to rev_func
    jal  rev_func           # first call to rev_func to reverse 
    la   $a0, ($s4)
    jal  rev_func           # second call to rev_func to print original
    addi $s3, $s3, -1       # decrement argument counter
    addi $s4, $s4, 4        # increment argument index
    beqz $s3, exit          # jump exit when arg count == 0
    j    cmdline 
    
    lw   $ra, 20($sp)       # restore return address
    lw   $fp, 16($sp)       # restore frame pointer
    addi $sp, $sp, 32       # pop stack frame

.end main
    
exit:
    li   $v0, 10            # load exit prog syscall
    syscall

error:
    #load errmsg and make syscall to print string
    la   $a0, errmsg  
    li   $v0, 4
    syscall
    j    exit

.globl rev_func
.ent rev_func
rev_func:
    addi $sp, $sp, -36    # stack frame is 32 bytes long
    sw   $ra, 24($sp)     # save return address
    sw   $fp, 28($sp)     # save frame pointer
    addi $fp, $sp, 32     # set up frame pointer
    sw   $a0, 0($fp)      # save values from main 
    sw   $s0, 0($sp)      # save values from main 
    sw   $t0, 4($sp)      # save values from main 
    sw   $t1, 8($sp)      # save values from main
    sw   $t2, 12($sp)     # save values from main
    sw   $t3, 16($sp)     # save values from main
    sw   $t4, 20($sp)     # save values from main

    #   0($sp) 4($sp) 8($sp)  12($sp) 16($sp) 20($sp) 24($sp) 28($sp) 0($fp)
    #   |------|------|-------|-------|-------|-------|-------|-------|------|
    #   0      4      8       12      16      20      24      28     32     36
    #                                                  [$ra]    [$fp]   [$a0]    
L1:    
    lw   $t0, ($a0)
L2:
    move $t4, $t0   
    move $s0, $t0   

find_end:
    lbu  $t1, 0($t0)
    beqz $t1, done 

    addu $t0, $t0, 1

    # print the current character for debugging
    # li $v0, 11 
    # move $a0, $t1 
    # syscall

    b find_end 
done:

    subu $t0, $t0, 1    # back up one byte before the null character

swap:
    # done when pointers t4 (start) and t0 (end) meet
    bgeu $t4, $t0, print_rev   

    # exchange characters
    lbu  $t2, 0($t4)
    lbu  $t3, 0($t0)
    sb   $t2, 0($t0)
    sb   $t3, 0($t4)

    # print the characters you are exchanging for debugging
    # li $v0, 11 
    # move $a0, $t3 
    # syscall
    # move $a0, $t2 
    # syscall

    # step to the next pair
    addu  $t4, $t4, 1
    subu  $t0, $t0, 1
    b swap

print_rev:
    # add null character to the end of the string
    # sb $zero, 1($t4)

    # display string
    li    $v0, 4
    move  $a0, $s0
    syscall

    la    $a0, newline
    syscall
    
    lw    $ra, 24($sp)     # restore $ra
    lw    $fp, 28($sp)     # restore frame pointer
    lw    $a0, 0($fp)      # restore values from caller 
    lw    $s0, 0($sp)      # restore values from caller 
    lw    $t0, 4($sp)      # restore values from caller 
    lw    $t1, 8($sp)      # restore values from caller
    lw    $t2, 12($sp)     # restore values from caller
    lw    $t3, 16($sp)     # restore values from caller
    lw    $t4, 20($sp)     # restore values from caller
    addi  $sp, $sp, 36     # pop stack frame
    jr    $ra              # return to caller
.end rev_func
