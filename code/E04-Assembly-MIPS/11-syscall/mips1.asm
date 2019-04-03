.data

array1:		.asciiz    "Ciao mondo!"

.text
	la $a0, array1
	addi $v0, $zero, 4
	syscall
	addi $v0, $zero, 10
	syscall
	
