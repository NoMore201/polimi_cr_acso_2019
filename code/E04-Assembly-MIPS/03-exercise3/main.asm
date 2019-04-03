#-----------------------------------------------------------
# Program    : exercise3.asm
# Written by : Domenico Iezzi
# Date       : 26/03/2019
# Description: introduction to MARS
#-----------------------------------------------------------

# DATA Segment
.data
A:	.word	21

# TEXT Segment
.text
	la	$s0, A
	lw	$s1, ($s0)
	addi	$s1, $s1, -5
	sw	$s1, ($s0)
