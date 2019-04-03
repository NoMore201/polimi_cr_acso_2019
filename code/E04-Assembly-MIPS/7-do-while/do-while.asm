#-----------------------------------------------------------
# Program    : do-while.asm
# Written by : Domenico Iezzi
# Date       : 26/03/2019
# Description: do-while statement
#-----------------------------------------------------------

# DATA Segment
        .data

# CODE Segment
	.text
main:
	addi $s0, $zero, 0
	addi $s1, $zero, 0
do:
	add $s0, $s0, $s1
	addi $s1, $s1, 1
	slti $s2, $s1, 5
	beq $s2, $zero, end
	j do
end:
