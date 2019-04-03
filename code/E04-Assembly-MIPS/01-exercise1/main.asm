#-----------------------------------------------------------
# Program    : exercise1.asm
# Written by : Domenico Iezzi
# Date       : 26/03/2019
# Description: introduction to MARS
#-----------------------------------------------------------

# DATA Segment
.data
value1:		.word 256

# TEXT Segment
.text
main:
	addi $s0, $zero, 1
	addi $s1, $s0, 4
