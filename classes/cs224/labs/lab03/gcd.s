# filename: gcd.s
# purpose: 
# read two integers from the cmdline and return greatest common denominator 

.data
newline: .asciiz "\n"
errmsg:
    .asciiz   "\nUsage: spim -f gcd.s <int> <int>\n\n"

.text
.globl main

main:

  # grab command line stuff - a0 is arg count and a1 points to list of args
  move $s0, $a0
  move $s1, $a1

  # zero out these registers just to be safe
  move $s2, $zero
  move $s3, $zero
  move $s4, $zero
     
  # check if two arguments are given
  li $t0, 2
  ble $a0, $t0, error
     
  # parse the first number
  lw $a0, 4($s1)
  jal atoi
  move $s2, $v0
     
  # parse the second number
  lw $a0, 8($s1)
  jal atoi
  move $s3, $v0
   
  # load a0 and a1 with two integers
  move   $a0, $s2 
  move   $a1, $s3

  move $t0, $a0
  move $t1, $a1

loop:
  beq $t1, $0, done
  div $t0, $t1
  move $t0, $t1
  mfhi $t1
  j loop

done:
  # move the result from t0 to v0 to print it
  move $a0, $t0     
  li $v0, 1
  syscall

  la $a0, newline     
  li $v0, 4
  syscall
 
  li $v0, 10   # exit
  syscall


error:
    # print error message
    li $v0, 4
    la $a0, errmsg
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

