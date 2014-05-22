.data
prompt: .asciiz "Enter a string w/ some white space after it: \n"
user_string: .word 0:10

.text
.globl main
.ent main
main:
    li    $v0, 4
    la    $a0, prompt       # load prompt
    syscall 
    li    $v0, 8            # read string from the buffer
    syscall
    move  $s0, $a0          # store read string in $s0
    jal   chomp             # jump to chomp block

    li    $v0, 4
    move  $a0, $s0          # print chomped string
    syscall
    
    li    $v0, 11           # print newline
    li    $a0, 10
    syscall

    li    $v0, 10           # exit
    move  $a0, $zero
    syscall
.end main

.globl chomp
.ent chomp 
chomp:
    move  $t0, $s0
cl:
    lb    $t1, ($t0)
    beq   $t1, $zero, end 
    ble   $t1, 32, check   # ran into whitespace, check if next char is too
    addi  $t0, $t0, 1      # step to next index
    b     cl
check:
    lb    $t1, 1($t0)      # check if next char is whitespace or NULL
    beq   $t1, $zero, end   
    ble   $t1, 32, end     # ran into whitespace, check if next char is too
    addi  $t0, $t0, 1      # step to next index
    b     cl
end:
    li    $t1, 46          # load '.' char into $t1
    sb    $t1, ($t0)       # store '.' into current index in string
    sb    $zero, 1($t0)    # store '\0' into next index in string
    jr    $ra
.end chomp
