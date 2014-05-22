    .data
str0:  .asciiz "The sum of "
str1:  .asciiz " and "
str2:  .asciiz " is "
str3:  .asciiz "\n"
    .text
main:
    la $a0, str0        #load str0 address into $a0
    li $v0, 4           #load syscall 4 into $v0
    syscall             #make syscall

    lw $t0, num0        #load 15 into $t0
    lw $t1, num1        #load 45 into $t1

    move $a0, $t0
    li $v0, 1           #load syscall 4 into $v0
    syscall

    la $a0, str1        #load str1 address into $a0
    li $v0, 4           #load syscall 4 into $v0
    syscall             #make syscall

    move $a0, $t1
    li $v0, 1           #load syscall 4 into $v0
    syscall
    
    la $a0, str2        #load str2 address into $a0
    li $v0, 4           #load syscall 4 into $v0
    syscall             #make syscall

    addu $v1, $t0, $t1  #add $t0 and $t1, store in $v1
    
    move $a0, $v1
    li $v0, 1           #load syscall 4 into $v0
    syscall
    
    la $a0, str3        #load str3 address into $a0
    li $v0, 4           #load syscall 4 into $v0
    syscall             #make syscall

    li $v0, 10          #load syscall 10, end program
    syscall             #make syscall

    .data
num0:  .word 15
num1:  .word 45
