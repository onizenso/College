## for (int i=0; i < 6; i++)
## {
##    for (int j=0; j < i; j++)
##    {
##       cout << "x ";
##    }
##    cout << endl;
## }
 

.data

.text

.globl main
.ent main
main:
    li     $s0, 6              # load outer loop limit
    move   $t0, $zero          # use $t0 for inner loop limit
    move   $t1, $zero          # use $t1 for outer loop counter
    move   $t2, $zero          # use $t2 for inner loop counter
    move   $t3, $zero          # use $t2 for print char counter
    b      outer_loop

.globl outer_loop
outer_loop:
    beq    $t1, $s0, exit
    addi   $t1, $t1, 1
    jal    inner_setup
    li $a0, 10                 # load newline char
    li $v0, 11                 # load print_char syscall
    syscall
    j      outer_loop

.globl inner_setup
inner_setup:
    move   $t0, $t1            # move outer loop index to inner loop limit
    move   $t2, $zero

.globl inner_loop
inner_loop:
    beq    $t2, $t0, end_loop  # end loop when inner index == inner limit
    li     $a0, 120            # print 'x' char
    li     $v0, 11
    syscall
    li     $a0, 32             # print space char
    li     $v0, 11
    syscall
    addi   $t2, $t2, 1         # increment inner index
    j      inner_loop
end_loop:
    jr     $ra


exit:
    li $a0, 10            # load newline char
    li $v0, 11            # load print_char syscall
    syscall
    li $v0, 10
    syscall
