#-----------------------------------------------------------
# Program    : if-else.asm
# Written by : Domenico Iezzi
# Date       : 26/03/2019
# Description: Simple if-else statement
#-----------------------------------------------------------

# DATA Segment
        .data

# CODE Segment
	.text
main:
	addi $s0, $zero, 2 # variabile a
	addi $s1, $zero, 3 # variabile b
	sgt $s2, $s0, $s1
	sgt $s3, $s1, $zero
	and $s2, $s2, $s3
	beq $s2, $zero, end
	add $s4, $s0, $s1
	j end
else:
	sub $s4, $s0, $s1
end:

