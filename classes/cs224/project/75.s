.data

default_msg:
    .asciiz "no cmdline args passed\n"
errmsg:
    .asciiz "\nspim -f 70.s <string>\n\n"
newline:
    .asciiz "\n"

.text
.globl main

.ent main
main: 
    move $s0, $a0           #move number of cmd line args to $s0
    move $s1, $a1           #move base addy of cmd line arg to $s1
    move $s2, $zero         #zero out remaining storage registers
    move $s3, $zero         #not used yet, but a precautionary measure
    move $s4, $zero       
    li   $t0, 2          
    beq  $a0, $t0, cmdline  #print error cmdline args passed
    bne  $a0, $t0, default  #jump to default if no cmdline args

cmdline:
    #load cmdline arg and make syscall to print string
    lw   $a0, 4($s1)        #load cmdline string into $a0
    li   $v0, 4             #load print_string syscall
    syscall
    li   $a0, 10            #load newline ascii into $a0
    li   $v0, 11            #load print_char syscall
    syscall
    b    next

default:
    la   $a0, default_msg   #load default_msg in $a0
    li   $v0, 4             
    syscall
    move $t0, $a0
    b    loop

next: 
    lw   $s2, 4($s1)        #load cmdline arg base addy into $s2
    move $t0, $s2           #$t0 is loop counter, start array at base addy

loop: 
    lb   $t1, ($t0)         #load byte at $t0 into $t1
    beq  $t1, $zero, end_lp #break loop when $t1 is NULL
    move $a0, $t1           #load char into $a0
    li   $v0, 11            #load print_char syscall
    syscall
    li   $a0, 32            #load space ascii into $a0
    li   $v0, 11            #load print_char syscall          
    syscall
    addi $t0, 1             #set $t0 to addy of next byte
    b    loop

end_lp:
    li   $a0, 10            #load newline ascii into $a0  
    li   $v0, 11            #load print_char syscall          
    syscall

exit:
    li   $v0, 10            #load exit prog syscall
    syscall
.end main
    
error:
    #load errmsg and make syscall to print string
    la $a0, errmsg  
    li $v0, 4
    syscall
    j  exit
