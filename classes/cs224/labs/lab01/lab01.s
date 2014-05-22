
TWO = 2                      # MIPS supports named constants; e.g. C defines

     .data                   # what follows is data 
stuff: .asciiz "hi again" # the z adds a trailing \0 null char

     .text                   # code follows 
main:
     la $a0, stuff           # stuff is an address
     li $v0, 4               # 4 is syscall to print a string
     syscall                 # execute the call 

     lb $a0, dot             # load the value of the linefeed into a0 
     li $v0, 11              # 11 is syscall to print a char 
     syscall                 # execute the call 
     lb $a0, lf              # load the value of the linefeed into a0 
     syscall                 # execute the call 

     lw $a0, foo             # load value at address foo into a0 
     li $v0, 1               # 1 is syscall to print int
     syscall                 # execute the call 


     li $t0, 55              # load 55 into register t0
     move $a0, $t0           # copy value in reg t0 to reg a0
     li $v0, 1               # 1 is syscall to print int
     syscall                 # execute the print_int syscall 
 
     lb $a0, lf              # load the address of the linefeed into a0 
     li $v0, 11              # 11 is syscall to print a char 
     syscall                 # execute the call 

     li $v0, 10              # 10 is system call to exit
     syscall                 # execute the call 

     .data                   # more data - MIPS is not structured - mix it up
foo: .word TWO               # TWO is replaced with value 2
dot: .byte 46                # 46 is the ascii-decimal equivalent 
lf:  .byte 10                # 10 is an ascii linefeed 
