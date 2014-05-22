# filename: fib.s 
# Appendix A, pp A-27 to A-29
#
#    spim> re "fib.s"
#    spim> breakp main 
#    spim> run
#    spim> s
#    spim> p $sp 
#    spim> cont 
#
# this implements the following program:
#    int fib(n)
#    {
#         if (n == 0) return 0;
#         if (n == 1) return 1;
#         return fib(n-1) + fib(n-2);
#    }
#
.data
msg:            .asciiz "Fibonacci number %d is: "
usage_msg:      .asciiz "Usage: spim -f fib.s <fib-num>\n"
printf_buf:     .space 2

.text
.globl main      
.ent main     

main:
    # Refer to page A-27 for details. A MIPS frame is a minimum of 32 bytes:
    # $a0 - $a3, $ra and 4 bytes of padding to align on a double-word boundary
    # is 24 bytes. 
    # To save $fp, another 8 bytes are added (4 for $fp and 4 for padding), 
    # making the frame 32 bytes long. Even though $a0-$a3 are not saved to the 
    # stack, space is still reserved on the stack for them.

    move  $s0, $a0
    move  $s1, $a1
    lw    $a0, 4($s1)       
    jal   atoi
    move  $a0, $v0

    bne   $s0, 2, usage   # break to print usage msg when arg count != 2 

    addi  $sp, $sp, -32   # stack frame is 32 bytes long
    sw    $ra, 20($sp)    # save return address
    sw    $fp, 16($sp)    # save old frame pointer
    sw    $a0, 4($sp)     # save original count
    addi  $fp, $sp, 28    # set up frame pointer. Skips the padding


  
    # With ra and fp saved, main() can now make all its needed function calls
    addi  $a0, $a0, -2    # account for already knowing the first two fib #'s
    li    $a1, 1          # load first fib number into $a1
    li    $a2, 1          # load second fib number into $a2
    li    $a3, 0          # load second fib number into $a2
    jal   fib             # jump to fibonacci function
    move  $t0, $a1        # save the result to print later

    la    $a0, msg        # load address of msg string in $a0
    lw    $a1, 4($sp)     # load cmdline arg in $a1
    jal   printf
 
    move  $a0, $t0        # move fib return value to $a0
    li    $v0, 1          # syscall 1=print integer
    syscall 

    li    $a0, 10         # ascii newline
    li    $v0, 11         # syscall 1=print char 
    syscall 
    # Since the function calls are done, restore ra and fp 

    lw    $ra, 20($sp)    # restore return address
    lw    $fp, 16($sp)    # restore frame pointer
    addi  $sp, $sp, 32    # pop stack frame

    j     exit
.end main
 
usage:
    la    $a0, usage_msg
    li    $v0, 4
    syscall
    j     exit

.globl fib
.globl L2 
.globl L1
.ent fib                # entry for the fib procedure
fib:
    # As above, create a 32 byte frame to store a0-a3, ra and fp.
    # For the fib procedure, a0 will be saved in offset 28 from the
    # sp (offset 0 from the fp).

    addi  $sp, $sp, -32    # stack frame is 32 bytes long
    sw    $ra, 20($sp)     # save return address
    sw    $fp, 16($sp)     # save frame pointer
    addi  $fp, $sp, 28     # set up frame pointer
    sw    $a0, 0($fp)      # save counter
    sw    $a1, 4($sp)      # save fib(n) 
    sw    $a2, 8($sp)      # save fib(n-1)
    sw    $a3, 12($sp)     # save fib(n-2)

    #   0($sp) 4($sp) 8($sp)  12($sp) 16($sp) 20($sp) 24($sp) 0($fp)
    #   |------|------|-------|-------|-------|-------|-------|------|
    #   0      4      8       12      16      20      24      28     32
    #                                   [$fp]   [$ra]          [$a0]

    beqz  $a0, L1          # exit when counter is zero
    addi  $a0, $a0, -1     # decrement the counter
    
L2:
    move  $a3, $a2         # move fib(n-1) into $a3
    move  $a2, $a1         # move fib(n) into $a2
    addu  $a1, $a2, $a3    # add new fib(n-1) and fib(n-2), store in $a1 
    jal   fib              # make the recursive call
L1:                      
    lw    $ra, 20($sp)     # restore $ra
    lw    $fp, 16($sp)     # restore frame pointer
    addi  $sp, $sp, 32     # pop stack frame
    jr    $ra              # return to caller
.end fib

# printf.s  
# purpose:  MIPS assembly implementation of a C-like printf procedure 
# supports %s, %d, and %c formats up to 3 formats in one call to printf
# all arguments passed in registers (args past 3 are ignored)

# Register Usage: 
#    $a0,$s0 - pointer to format string 
#    $a1,$s1 - format arg1 (optional) 
#    $a2,$s2 - format arg2 (optional) 
#    $a3,$s3 - format arg3 (optional) 
#    $s4  - count of format strings processed so far
#    $s5  - holds the format string (%s,%d,%c,%) 
#    $s6  - pointer to printf buffer
#

.globl printf
.ent printf
printf:
    addi  $sp, $sp, -36      # setup stack frame
    sw    $ra, 32($sp)       # save local environment
    sw    $fp, 28($sp) 
    sw    $s0, 24($sp) 
    sw    $s1, 20($sp) 
    sw    $s2, 16($sp) 
    sw    $s3, 12($sp) 
    sw    $s4, 8($sp) 
    sw    $s5, 4($sp)
    sw    $s6, 0($sp)  
    addu  $fp, $sp, 36 
                             # grab the args and move into $s0..$s3 registers
    move $s0, $a0            # fmt string
    move $s1, $a1            # arg1 (optional)
    move $s2, $a2            # arg2 (optional)
    move $s3, $a3            # arg3 (optional)
 
    li   $s4, 0              # set argument counter to zero
    la   $s6, printf_buf     # set s6 to base of printf buffer
 
 
main_loop:                    # process chars in fmt string
    lb   $s5, 0($s0)          # get next format flag
    addu $s0, $s0, 1          # increment $s0 to point to next char
    beq  $s5, '%', printf_fmt # branch to printf_fmt if next char equals '%'
    beq  $0, $s5, printf_end  # branch to end if next char equals zero 
 
 
printf_putc: 
    sb   $s5, 0($s6)          # if here we can store the char(byte) in buffer 
    sb   $0, 1($s6)           # store a null byte in the buffer
    move $a0, $s6             # prepare to make printf_str(4) syscall  
    li   $v0, 4               # load integer 4 into $v0 reg              
    syscall                   # make the call
 
    b    main_loop            # branch to continue the main loop
 
printf_fmt: 
    lb   $s5, 0($s0)           # load the byte to see what fmt char we have 
    addu $s0, $s0, 1           # increment $s0 pointer 
 
    beq  $s4, 3,  main_loop    # if $s4 equals 3 branch to main_loop 
    beq  $s5,'d', printf_int   # decimal integer 
    beq  $s5,'s', printf_str   # string 
    beq  $s5,'c', printf_char  # ASCII char 
    beq  $s5,'%', printf_perc  # percent 
    b    main_loop             # if we made it here just continue 
 
 
printf_shift_args:            # code to shift to next fmt argument
    move  $s1, $s2             # assign $s2 to $s1 
    move  $s2, $s3             # assign $s3 to $s2 
    add   $s4, $s4, 1          # increment arg count
    b     main_loop            # branch to main_loop
 
printf_int:                   # print decimal integer
    move  $a0, $s1             # move $s1 into $v0 for print_int syscall
    li    $v0, 1               # load syscall no. 1 into $v0
    syscall                    # execute syscall 1
    b     printf_shift_args    # branch to printf_shift_args to process next arg
 
printf_str:
    move  $a0, $s1             # move buffer address $s1 to $a0 for print_str(4) 
    li    $v0, 4               # setup syscall - load 4 into $v0 
    syscall
    b    printf_shift_args     # branch to shift_arg loop
 
printf_char:                  # print ASCII character 
    sb    $s1, 0($s6)          # store byte from $s1 to buffer $s6
    sb    $0,  1($s6)          # store null byte in buffer $s6
    move  $a0, $s6             # prepare for print_str(1) syscall
    li    $v0, 4               # load 1 into $v0
    syscall                    # execute syscall 1
    b     printf_shift_args    # branch to printf_shift_args to process next arg
 
printf_perc: 
    li   $s5, '%'              # handle %%
    sb   $s5, 0($s6)           # fill buffer with byte %
    sb   $0, 1($s6)            # add null byte to buffer 
    move $a0, $s6              # prepare for print_str(4) syscall
    li   $v0, 4              
    syscall                    # execute the call
    b    main_loop             # branch to main_loop
 
 
printf_end:                # callee needs to clean up after itself
    lw   $ra, 32($sp)      # load word @ address $sp+32 into return address reg 
    lw   $fp, 28($sp)      # load word @ address $sp+28 into frame pointer reg 
    lw   $s0, 24($sp)      # save values at addresses $sp+24 ... $sp+0 
    lw   $s1, 20($sp)      
    lw   $s1, 16($sp)      
    lw   $s1, 12($sp)      
    lw   $s1,  8($sp)      
    lw   $s1,  4($sp)      
    lw   $s1,  0($sp)      
    addu $sp, $sp, 36      # release the stack frame
    jr   $ra               # jump to the return address
.end printf

exit:
    li   $v0, 10           #load shutdown syscall
    syscall

atoi:
    move $v0, $zero
     
    # detect sign
    li $t0, 1
    lbu $t1, 0($a0)
    bne $t1, 45, digit
    li $t0, -1
    addu $a0, $a0, 1

digit:
    # read character
    lbu $t1, 0($a0)
     
    # finish when non-digit encountered
    bltu $t1, 48, finish
    bgtu $t1, 57, finish
     
    # translate character into digit
    subu $t1, $t1, 48
     
    # multiply the accumulator by ten
    li $t2, 10
    mult $v0, $t2
    mflo $v0
     
    # add digit to the accumulator
    add $v0, $v0, $t1
     
    # next character
    addu $a0, $a0, 1
    b digit

finish:
    mult $v0, $t0
    mflo $v0
    jr $ra

