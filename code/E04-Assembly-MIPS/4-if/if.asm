#-----------------------------------------------------------
# Program    : if.asm
# Written by : Domenico Iezzi
# Date       : 26/03/2019
# Description: Simple if statement
#-----------------------------------------------------------

# DATA Segment
.data

# CODE Segment
.text
main:
	addi $s0, $zero, 1  # int a = 1
	addi $s1, $zero, 3  # int b = 3
	addi $s0, $s0, 1    # a = a + 1
	sgt $s2, $s0, $s1
	beq $s2, $zero, end
	add $s1, $s1, $s0   # b = b + a	
end:
