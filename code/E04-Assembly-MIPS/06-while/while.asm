#-----------------------------------------------------------
# Program    : while.asm
# Written by : Domenico Iezzi
# Date       : 26/03/2019
# Description: while statement
#-----------------------------------------------------------

# DATA Segment
        .data

# CODE Segment
	.text
main:
	addi $s0, $zero, 3
cond:
	sgt $s1, $s0, $zero
	beq $s1, $zero, end
	addi $s0, $s0, -1
	j cond
end:
