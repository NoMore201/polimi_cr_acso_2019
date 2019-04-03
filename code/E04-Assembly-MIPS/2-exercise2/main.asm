#-----------------------------------------------------------
# Program    : exercise2.asm
# Written by : Domenico Iezzi
# Date       : 26/03/2019
# Description: introduction to MARS
#-----------------------------------------------------------

# DATA Segment
.data
	.word 10, 12, 14
# CODE Segment
.text
	addi $s0, $zero, 2
	addi $s1, $s0, -5
	mul  $s2, $s1, $s0
	add  $s2, $s2, $s0
	sub  $s3, $s2, $s1
