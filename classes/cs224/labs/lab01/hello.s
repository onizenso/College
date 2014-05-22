    .data
stuff:  .asciiz "Hello Everybody!\n"
    .text
main:
    la $a0, stuff #load 'stuff' address into $a0
    li $v0, 4     #load syscall 4 into $v0
    syscall       #make syscall
    li $v0, 10    #load syscall 10, end program
    syscall       #make syscall
