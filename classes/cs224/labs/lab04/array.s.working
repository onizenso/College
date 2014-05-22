## 1.   declares an array to hold 30 integers
## 2.   uses one loop to initialize the array with the first 30 odd integers; 
##      display the values to the screen within the loop
## 
##     1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45  
## 
## 3.   uses a second loop to step through the array and display only 
##      those integers that are evenly divisable by 3 or 7
## 
##      3 7 9 15 21 27 33 35 39 45 49 51 57   # there are 13

.data
newline:  .asciiz "  \n"
array:    .word  0:30         # allocate space for 30 integers, init 0 


.text

.globl main
.ent main
main:
    move  $s0, $zero          # $s0 used to hold the integers
    move  $s1, $zero          # $s0 used to hold the integers
    move  $s3, $zero          # $s3 used to hold 3 
    move  $s4, $zero          # $s4 used to hold 7
    move  $t0, $zero          # $t0 used to array index counter
    la    $s0, array          # load the address of the array into $s0
    move  $t0, $s0
    li    $s1, 29             # store array size-1 in $s1
    li    $s3, 3              # store 3 into $s3
    li    $s4, 7              # store 7 into $s4
    li    $t1, 1              # $t1 used to step through the integers
    move  $t2, $s1            # $t2 is the counter from array capacity
    jal   fill_array
.end main

.globl fill_array
fill_array:
    beqz  $t2, done          # jump to display the array when counter reaches 0
    sw    $t1, ($t0)
    addi  $t1, $t1, 2         # add 2 to get next odd int
    addi  $t0, $t0, 4         # add 4 to $t0 to move to next index in the array
    addi  $t2, $t2, -1
    j     fill_array

done:
    jal   reset

.globl display 
display:
    beq   $t3, $s1, cont      # break when index == array size
    lw    $a0, ($t0)          # load int from the array
    li    $v0, 1              # print the int
    syscall
    li    $a0, 32             # load ascii space to print
    li    $v0, 11             # print the space
    syscall
    addi  $t0, $t0, 4         # increment to next int in the array
    addi  $t3, $t3, 1         # increment to next index in the array
    j     display

cont:
    li    $a0, 10             # load ascii newline
    li    $v0, 11             # print the newline
    syscall
    jal   reset
    j     test_mod

.globl test_mod
test_mod:
    beq   $t3, $s1, exit   
    lw    $t4, ($t0)          # store the next int into $t4
    divu  $t4, $s3            # divide int by 3
    mfhi  $t1                 # store mod remainder in $t1
    beqz  $t1, print_mod      # when mod result from 3 is zero print int
    divu  $t4, $s4            # divide int by 7
    mfhi  $t1                 # store mod remainder in $t1
    beqz  $t1, print_mod      # when mod result from 7 is zero print int
    addi  $t0, $t0, 4         # increment to next int
    addi  $t3, $t3, 1         # increment to next index
    j     test_mod

.globl print_mod
print_mod:
    move  $a0, $t4
    li    $v0, 1
    syscall
    li    $a0, 32               # load ascii space to print
    li    $v0, 11               # print the space
    syscall
    addi  $t0, $t0, 4           # increment to next int
    addi  $t3, $t3, 1           # increment to next index
    j     test_mod

.globl reset
reset:
    move  $t0, $s0
    move  $t3, $zero          # use  $t3 as the index of the array
    jr    $ra

.globl exit
exit:
    li    $a0, 10             # load ascii newline
    li    $v0, 11             # print the newline
    syscall
    li    $v0, 10
    syscall
