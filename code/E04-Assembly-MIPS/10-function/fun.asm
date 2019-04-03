#-----------------------------------------------------------
# Program    : fun.asm
# Written by : Domenico Iezzi
# Date       : 26/03/2019
# Description: esercizio su funzione
#-----------------------------------------------------------

# DATA Segment
.data

# TEXT Segment
.text
main:	addi	$a0, $zero, 1   # arg1
	addi	$a1, $zero, 2   # arg2
	addi	$a2, $zero, 3   # arg3
	addi	$a3, $zero, 4   # arg4
	jal	leaf
	move 	$s0, $v0
	j exit
	
leaf:
	addi	$sp, $sp, -20
	sw	$ra, 16($sp)    # save return address to stack
	sw	$a0, 12($sp)    # save arg0 to stack
	sw	$a1, 8($sp)     # save arg1 to stack
	sw 	$a2, 4($sp)     # save arg2 to stack
	sw	$a3, ($sp)      # save arg3 to stack
	add	$t0, $a0, $a1
	add	$t1, $a2, $a3
	sub	$s0, $t0, $t1
	move	$a0, $s0
	jal	multiplier
	lw	$ra, 16($sp)   # restore return address
	lw	$a0, 12($sp)   # restore arg0
	lw	$a1, 8($sp)    # restore arg1
	lw	$a2, 4($sp)    # restore arg2
	lw	$a3, ($sp)     # restore arg3
	jr	$ra
	
multiplier:
	sll	$v0, $a0, 2
	jr	$ra

exit:

