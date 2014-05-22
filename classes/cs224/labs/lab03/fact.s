# filename: fact.s 
# Appendix A, pp A-27 to A-29
#
#    spim> re "fact.s"
#    spim> breakp main 
#    spim> run
#    spim> s
#    spim> p $sp 
#    spim> cont 
#
# this implements the following program:
#
#         int main() {
#              printf("The factorial of 5 is %d\n", fact(5));
#         }
#         int fact (int n) {
#             if (n < 1) return 1;
#         else return n * fact(n-1);
#         }
#
# OR
#   $ spim -f fact.s
#   $ The factorial of 5 is 120. 
#

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

    addi  $sp, $sp, -32   # stack frame is 32 bytes long
    sw    $ra, 20($sp)    # save return address
    sw    $fp, 16($sp)    # save old frame pointer
    addi  $fp, $sp, 28    # set up frame pointer. Skips the padding

  
    # With ra and fp saved, main() can now make all its needed function calls
    li    $a0, 5          # load argument (5) in $a0
    jal   fact            # jump to factorial function
    move  $t0, $v0        # save the result to print later

    la    $a0, msg        # load address of msg string in $a0
    li    $v0, 4          # syscall 4=print string
    syscall 
 
    move  $a0, $t0        # move fact return value to $a0
    li    $v0, 1          # syscall 1=print integer
    syscall 

    li    $a0, 10         # ascii newline
    li    $v0, 11         # syscall 1=print char 
    syscall 
    # Since the function calls are done, restore ra and fp 

    lw    $ra, 20($sp)    # restore return address
    lw    $fp, 16($sp)    # restore frame pointer
    addi  $sp, $sp, 32    # pop stack frame

    li    $v0, 10         # 10 is the exit syscall
    syscall               # execute the exit

.end main


    .rdata                # rdata section contains static constant data
msg:
    .asciiz "The factorial of 5 is "

.text                    # another segment of instructions
 
.ent fact                # entry for the fact procedure
fact:
    # As above, create a 32 byte frame to store a0-a3, ra and fp.
    # For the fact procedure, a0 will be saved in offset 28 from the
    # sp (offset 0 from the fp).

    addi  $sp, $sp, -32    # stack frame is 32 bytes long
    sw    $ra, 20($sp)     # save return address
    sw    $fp, 16($sp)     # save frame pointer
    addi  $fp, $sp, 28     # set up frame pointer
    sw    $a0, 0($fp)      # save argument (n)

    #   0($sp) 4($sp) 8($sp)  12($sp) 16($sp) 20($sp) 24($sp) 0($fp)
    #   |------|------|-------|-------|-------|-------|-------|------|
    #   0      4      8       12      16      20      24      28     32
    #                                   [$fp]   [$ra]          [$a0]

    lw    $v0, 0($fp)      # load n
    bgtz  $v0, L2          # branch to L2 if value in v0 is greater than 0
    li    $v0, 1           # load 1 into the return value register
    j     L1               # unconditional jump to L1

L2:
    lw    $v1, 0($fp)      # load n
    addi  $a0, $v1, -1     # compute n - 1
    jal   fact             # make the recursive call

    lw    $v1, 0($fp)      # load n
    mul   $v0, $v0, $v1    # compute fact(n-1) * n; put return value in $v0

L1:                      
    lw    $ra, 20($sp)     # restore $ra
    lw    $fp, 16($sp)     # restore frame pointer
    addi  $sp, $sp, 32     # pop stack frame
    jr    $ra              # return to caller

.end fact
