.data
unsigned: .word 0:5
.text
.ent main
main:
li     $t0, 0x10000
li     $t1, 0x10000
addi   $t1, $t1, -1
mul    $a0, $t0, $t1
addu   $a0, $a0, $t1
#la     $t2, unsigned
#sw     $a0, ($t2)
#move   $a0, $t2
li     $v0, 4

syscall
li     $v0, 10
syscall
.end main
