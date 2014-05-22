# filename: main.s
# purpose:  test output facilities in print.s and input facilities in read.s

#  spim> re "main.s"
#  spim> re "printf.s"
#  spim> re "read.s"
#  spim> run
#  spim> exit 

.text
.globl main
.globl read

.ent read
read:

  # prompt user to input first name
  la $a0, fnprompt  # load address of first name prompt 
  li $v0, 4         # load immediate with 4 to setup syscall 4 (print_str)
  syscall           # display the prompt

  # read the first name and store it
  li $v0, 8        # setup syscall 8 (read_string)
  syscall          # address of string buffer returned in $a0
  move $t0, $a0    # load first name into $t0

  # prompt user to input last name
  la $a0, lnprompt  # load address of first name prompt 
  li $v0, 4         # load immediate with 4 to setup syscall 4 (print_str)
  syscall          # display the prompt

  # read the last name and store it
  li $v0, 8        # setup syscall 8 (read_string)
  syscall          # address of string buffer returned in $a0
  move $t1, $a0    # load last name into $t1

  # prompt user to input an id
  la $a0 idprompt   # load address of prompt into $a0 for print_str
  li $v0 4         # load immediate with 4 to setup syscall 4 (print_str)
  syscall          # display the prompt 

  # read the id and store it
  li $v0, 5        # setup syscall 5 (read_int)
  syscall          # address of string buffer returned in $a0
  move $t2, $v0    # move id into $t2

  jr $ra
.end read

.ent  main
main:
  jal   read             # run the read procedure

  la    $a0, nameformat  # Load address of nameformat into $a0
  move  $a1, $t0         # pass first name in $t0 into $a1
  jal   printf           # call printf

  la    $a0, nameformat  # load address of nameformat into $a0
  move  $a1, $t1         # pass last name in $t1 into $a1
  jal   printf           # call printf

  la    $a0, idformat    # load address of idformat into $a0
  move  $a1, $t2         # pass id in $t2 into $a1
  jal   printf           # call printf

  li    $v0,10           # 10 is exit system call
  syscall    

.end  main

.data
fnprompt: 
  .asciiz "Enter first name [return]:\n"   # prompts for first name
lnprompt: 
  .asciiz "Enter last name [return]:\n"    # prompts for last name
idprompt: 
  .asciiz "Enter id (3-digit) [return]:\n" # prompts for id
nameformat: 
  .asciiz "%s"                             # prints name string and newline
idformat: 
  .asciiz "%d\n"                             # prints id and newline
