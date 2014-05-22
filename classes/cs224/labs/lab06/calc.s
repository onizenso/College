# filename: calc.s
# description: cs 224 lab 06 

# prompt the user to enter two integers, sum integers and display the result

.text
.globl main 
.ent  main
main:
  bne   $a0, 4, usage   # if argc != 4 print usage message, exit program
  move  $s1, $a1

  lw    $s3, 8($s1)
  #lb    $a0, ($s3)
  #li    $v0, 11
  #syscall 

  lw    $a0, 4($s1)    #  convert first char into integer
  jal   atoi
  move  $s0, $v0 

  lw    $a0, 12($s1)    #  convert second char into integer
  jal   atoi
  move  $s2, $v0 
 
  jal   calc
  move  $a0, $s3
  jal   parity

exit:
  li  $v0, 10          # 10 is exit system call
  syscall    
.end  main

.globl calc
.ent calc
calc:
  lb    $t7, ($s3)

  li    $t3, 43       # load ascii decimal for '+' into $t3
  li    $t4, 45      # load ascii decimal for '-' into $t4

  beq   $t7, $t3, adding
  beq   $t7, $t4, subtract
 
adding:
  # sum the two integers
  add   $a0, $s0, $s2
  li    $v0, 1          # setup syscall 1 (print_int)
  syscall              # make the call to display the integer 
  j     calc_done 

subtract:
  # sub the two integers
  li    $v0, 1          # setup syscall 1 (print_int)
  sub   $a0, $s0, $s2
  syscall              # make the call to display the integer 
  j     calc_done   

calc_done:
  move  $s3, $a0 
  li    $v0, 4            # print newline
  la    $a0, newline  
  syscall          
  jr    $ra
.end calc

.globl parity
.ent parity
parity:
  move  $t0, $a0
  li    $t1, 2
  div   $t0, $t1
  mfhi  $t1
  beqz  $t1, isEven
  la    $a0, odd_msg
  b     exitPar
isEven:
  la    $a0, even_msg
exitPar:
  li    $v0, 4 
  syscall
  la    $a0, newline
  syscall
.end parity

.globl atoi
.ent atoi
atoi:
  addi $sp, $sp, -32  # setup stack frame
  sw   $t0, 0($sp)    # store $t0 value from caller
  sw   $t1, 4($sp)    # store $t0 value from caller
  sw   $t2, 8($sp)    # store $t0 value from caller
  
  move $v0, $zero

  # detect sign
  li   $t0, 1
  lbu  $t1, 0($a0)
  bne  $t1, 45, digit
  li   $t0, -1
  addu $a0, $a0, 1

digit:
  # read character
  lbu  $t1, 0($a0)

  # finish when non-digit encountered
  bltu $t1, 48, finish
  bgtu $t1, 57, finish

  # translate character into digit
  subu $t1, $t1, 48

  # multiply the accumulator by ten
  li   $t2, 10
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
  lw   $t0, 0($sp)    # store $t0 value from caller
  lw   $t1, 4($sp)    # store $t0 value from caller
  lw   $t2, 8($sp)    # store $t0 value from caller
  addi $sp, $sp, 32   # return stack frame 
  jr   $ra
.end atoi

.globl usage
usage:
  li    $v0, 4
  la    $a0, use_msg
  syscall
  j     exit

.data
even_msg: .asciiz "EVEN"
odd_msg: .asciiz "ODD"
minus: .asciiz "-"
plus:  .asciiz "+"
newline: .asciiz "\n"
use_msg: .asciiz "spim -f calc.s <num1> <+/-> <num2>\n"
