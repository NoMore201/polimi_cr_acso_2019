#-----------------------------------------------------------
# Program    : for.asm
# Written by : Domenico Iezzi
# Date       : 26/03/2019
# Description: For statement
#-----------------------------------------------------------

# DATA Segment
	.data

# TEXT Segment
	.text
	addi	$s0, $zero, 1
init:	add 	$s1, $zero, $zero
cond:	sle	$s2, $s1, 5
	bne	$s2, $zero, end
	mul	$s0, $s0, $s1
inc:	addi	$s1, $s1, 1
	b	cond
end:

