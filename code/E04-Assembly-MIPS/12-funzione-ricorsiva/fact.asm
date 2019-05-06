#-----------------------------------------------------------
# Program    : fact.asm
# Written by : Domenico Iezzi
# Date       : 26/03/2019
# Description: Implementazione della funzione fattoriale
#-----------------------------------------------------------
.data

.text
	addi $a0, $zero, 6
	jal fact
	j exit

fact:
	li $t0, 0
	beq $t0, $a0, return1
	
	li $t0, 1
	beq $t0, $a0, return1
	
	# chiamata ricorsiva
	addi $sp, $sp, -8
	sw $a0, ($sp)
	sw $ra, 4($sp)
	addi $a0, $a0, -1
	jal fact
	
end:
	# ripristino dati dallo stack
	lw $a0, ($sp)
	lw $ra, 4($sp)
	addi $sp, $sp, 8

	# aggiornare valore
	mul $v0, $v0, $a0
	jr $ra

return1:
	li $v0, 1
	jr $ra

exit:
	
