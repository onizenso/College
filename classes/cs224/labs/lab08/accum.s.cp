#  filename: accum.s
#
#  purpose: reads in a list of numbers from the command line, displays the
#  args, accumulates and displays result:
#       $ spim -f accum.s 10 20 30 15
#       $ 5accum.s10203015
#       $ 75
#  If nothing is passed it force loads some cmdline args and processes them
#  in the same way. Any argument that is NAN (not a number) is ignored.
# 
#  If debugging code is uncommented displays each arg and its ascii equiv. 
#  to screen.
#
#  For debugging forceload the args and run inside spim to set breakpoints:
# 
#       spim> re "accum.c"
#       spim> breakp got_num 
#       spim> s 

# Register Usage: 
#                 s0 holds the number of cmdline args
#                 s2 holds address of current arg
#                 s3 is the accumulator

     .data

# this is your arg structure
myargs: 
    .word   0:6        # this will hold 6 addresses (they must be aligned)
arg1: .asciiz "test.s"
arg2: .asciiz "91"
arg3: .asciiz "8"
arg4: .asciiz "10"
arg5: .asciiz "xyz"      # this will be ignored
arg6: .asciiz "1"

newline: .asciiz "\n"
itsanum: .asciiz   " num\n"
itsnan:  .asciiz   " NAN\n"
errmsg:  .asciiz   "An error of some sort occurred."
 
    .text

    # do this so you can set debugging breakpoints
    .globl main      
    .globl got_num
    .globl got_nan
    .globl loadargs 
    .globl argsloop 

main:
    addi $t1, $zero, 1 
    bgt  $a0,$t1,L1    # if args were passed then do not force load    
    jal  loadargs      # force-load hard-coded cmdline args
L1:
    move $s0, $a0      # s0 holds the number of cmdline args
    move $s1, $a1      # s1 holds the base address of cmdline array
    jal  printargs     # print the cmdline args for verification

    # initialize some stuff
    move $s3, $zero     # accumulator
    move $t6, $zero     # t6 is loop counter, init to zero, exit when $t6 = $s0
    li  $t5, 48         # 48 is the ascii value of letter 0 (zero)
    move $t7, $s1       # array index 

argsloop: 
 
    # increment at loop top to step past the first arg         
    addi $t6, $t6, 1    # increment loop counter 
    addi $t7, $t7, 4    # increment array index by 4

    beq $t6, $s0, exit  # exit loop when you have processed all args

    lw $s2, ($t7)       # s2 holds the address of the current arg 

    # for debugging print the arg 
    #move $a0, $s2       # move address into a0 to print arg
    #li $v0, 4           
    #syscall     

    # for debugging print the first char of the arg 
    # lbu $a0, ($s2)      # load first character of current arg into a0 
    # move $t8, $a0       # move the byte into t8
    # li $v0, 11          # print the char
    # syscall     
   
    # for debugging print the ascii equiv of the first byte of the current arg 
    # lbu $a0, ($s2)     # load first character of current arg into a0 
    # li $v0, 1          # print the ascii decimal value of the byte (char) 
    # syscall 
   
    lbu $t8, ($s2)      # load first character of current arg into a0 
    li  $t5, 48         # 48 is the ascii value of digit 0
    bge $t8, $t5, got_num 

    b got_nan             # otherwise you got an operator

got_num:
    # for debugging 
    #li $v0, 4 
    #la $a0, itsanum
    #syscall

    move $a0, $s2          # move the address of the number string into a0

    jal atoi               # convert the string into an integer
    add $s3, $s3, $v0      # add to accumulator
    # for debugging print the accumulator  as you go
    # move $a0, $v0          
    # li $v0, 1 
    # syscall 

    b argsloop 


got_nan:                   # Not A Number
    # for debugging 
    # li $v0, 4 
    # la $a0, itsnan     
    # syscall

    b argsloop 

error:
    # print error message
    li $v0, 4
    la $a0, errmsg
    syscall

exit:
    li $v0, 4 
    la $a0, newline
    syscall

    li $v0, 1
    move $a0, $s3
    syscall

    li $v0, 4 
    la $a0, newline
    syscall

    # exit program 
    li $v0, 10   
    li $a0, 0
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


loadargs:

  li $a0, 6        # the number of args
  la $a1, myargs   # a1 is the base pointer to the array of addresses 

  # load the array with addresses to the arguments
  la $t0, arg1
  sw $t0, 0($a1)

  la $t0, arg2
  sw $t0, 4($a1)

  la $t0, arg3
  sw $t0, 8($a1)

  la $t0, arg4
  sw $t0, 12($a1)

  la $t0, arg5
  sw $t0, 16($a1)

  la $t0, arg6
  sw $t0, 20($a1)

  jr $ra


printargs:

  move $t3, $a0     # t3 is loop counter - starts at num of cmd args
  move $t4, $a1     # t4 is index into the array 

  # print no of args
  li $v0, 1           
  syscall


  # loop through the arg array and display args to screen
  li $v0, 4           
loop:
  beq $t3, $zero, done

  # load address of first arg into $a0 for print_str
  lw $a0, ($t4)     
  syscall         

  # increment index 
  addi $t4, $t4, 4 

  # decrement loop counter
  addi $t3, $t3, -1 
  b loop

done:
  la $a0, newline 
  syscall        
  jr $ra
