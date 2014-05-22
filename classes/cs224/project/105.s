.data

default_msg:
    .asciiz "no cmdline args passed\n"
errmsg:
    .asciiz "\nspim -f 105.s <string>\n\n"
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

    move $a0, $s4           # load current string into $a0 to pass to rev_func
    jal  rev_func           # first call to rev_func to reverse 
    move $a0, $s4
    jal  rev_func           # second call to rev_func to print original
    
    move $a0, $s4
    jal  to_upper           # jump to to_upper function
    lw   $a0, ($s4)
    li   $v0, 4             # print string in $a0
    syscall
    li   $a0, 10            # load newline ascii into $a0  
    li   $v0, 11            # load print_char syscall          
    syscall
    
    move $a0, $s4           # load current string address into $a0
    jal  sort_string
    lw   $a0, ($s4)
    li   $v0, 4             # print string in $a0
    syscall
    li   $a0, 10            # load newline ascii into $a0  
    li   $v0, 11            # load print_char syscall          
    syscall
    
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
    addi $sp, $sp, -36    # stack frame is 36 bytes long
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
    lbu  $t1, ($t0)
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

# do
# {
#   character = string[i];
#   if ( character < 97 )
#      continue;
#   else
#   {
#      character -= 32;
#      continue;
#   }
#   i++;
# } while(character);
.globl to_upper
.ent to_upper
to_upper:
    lw    $t8, ($a0)            # use $t8 to step through the string    

start_upper:
    lbu   $t9, ($t8)            # load byte at the $t8 index
    beqz  $t9, return           # return to caller, reached end of string
    bge   $t9, 97, convert      # convert to upper otherwise
    addi  $t8, $t8, 1           # step to next byte in string
    b     start_upper           # continue if char already upper

convert:
    addi  $t9, $t9, -32         # convert character to upper
    sb    $t9, ($t8)            # store byte at the $t8 index
    addi  $t8, $t8, 1           # step to next byte in string
    b     start_upper

return:
    lw    $a0, ($s4)
    li    $v0, 4                # print string in $a0
    syscall
    li    $a0, 10                # load newline ascii into $a0  
    li    $v0, 11                # load print_char syscall          
    syscall
    jr    $ra
.end to_upper

# base = string_address;
# offset = 0;
# cur_char = *(base + offset);
# while(cur_char)
# {
#    unsorted_addy = (base + outter_offset);
#    inner_offset = outter_offset;
#    do
#    {
#       low = *(base + inner_offset);
#       next = *(base + inner_offset + 1);
#       if(low < next)
#           low = next;
#       inner_offset++;
#    } while(next);
#    temp = cur_char;
#    cur_char = low;
#    offset++;
#    cur_char = *(base + outter_offset);
# }
.ent sort_string
sort_string:
    addi  $sp, $sp, -32          # stack frame is 32 bytes long
    sw    $ra, 24($sp)           # save return address
    sw    $a0, 20($sp)           # save passed argument
    lw    $t6, ($a0)             # use $t6 as the outer counter
outter_sort:                     # begin outer loop
    lb    $t7, ($t6)
    beqz  $t7, end_sort
    move  $t5, $t6               # use $t5 as the inner counter 
    addi  $t4, $t5, 1
 
inner_sort:
    lb    $t8, ($t5)             # load byte (inner_offset) in $t8
    lb    $t9, ($t4)             # load byte (inner_offset + 1) to $t9
    beqz  $t9, cont_out
    blt   $t9, $t8, swap_inner   # break out of inner loop when $t9 < $t8
    addi  $t4, $t4, 1            # inner_offset++
    j     inner_sort
swap_inner:
    sb    $t9, ($t5)             # store found low in outter index
    sb    $t8, ($t4)             # store old current char in outter index + 1
    addi  $t4, $t4, 1            # inner_offset++
    j     inner_sort
cont_out:
    addi  $t6, $t6, 1            # outter_offset++
    j     outter_sort 

end_sort:
    lw    $ra, 24($sp)           # save return address
    lw    $a0, 20($sp)           # save passed argument
    addi  $sp, $sp, 32           # stack frame is 32 bytes long
    jr    $ra 
.end sort_string
