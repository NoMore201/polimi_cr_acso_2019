#-----------------------------------------------------------
# Program    : mips1.asm
# Written by : Domenico Iezzi
# Date       : 26/03/2019
# Description: esercizio su system calls
#-----------------------------------------------------------

# DATA Segment
.data

array1:		.asciiz    "Ciao mondo!"

# TEXT Segment
.text
	la $a0, array1
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 10
	syscall
	
