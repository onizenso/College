.data

errmsg:
    .asciiz "\nspim -f 70.s <string>\n\n"
newline:
    .asciiz "\n"

.text
.ent main
main:
    move $s0, $a0         #move number of cmd line args to $s0
    move $s1, $a1         #move array of cmd line args to $s1
    move $s2, $zero       #zero out remaining storage registers
    move $s3, $zero       #not used yet, but a precautionary measure
    move $s4, $zero       

    li   $t0, 1          
    ble  $a0, $t0, error  #print error if no args passed

    lw   $a0, 4($s1)      #move first cmdline arg to $a0
    li   $v0, 4           #print string
    syscall

    la   $a0, newline     #move newline to $a0
    li   $v0, 4           #print string
    syscall

exit:
    li   $v0, 10          #load exit prog syscall
    syscall
    
error:
    #load errmsg and make syscall to print string
    la $a0, errmsg  
    li $v0, 4
    syscall
    j  exit
