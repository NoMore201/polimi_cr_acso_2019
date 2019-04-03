#-----------------------------------------------------------
# Program    : vector.asm
# Written by : Domenico Iezzi
# Date       : 26/03/2019
# Description: esercizio su vettori
#-----------------------------------------------------------

#
# Calcolo indirizzo elemento i-esimo del vettore
#
# v[i] <-> v + ( i * 4 )
#   dove 4 è la dimensione in memoria dell'elemento
#   dell'array (nel nostro caso una word da 4 byte)
# 
#


# DATA Segment
.data
v:	.word	1, 2, 3, 4, 5

# TEXT Segment
.text
init:	add 	$s0, $zero, $zero  # i = 0
cond:	slti 	$s1, $s0, 5        # condizione i < 5
	beq	$s1, $zero, end    # salto a 'end' se la condizione non è
				   # verificata
	la	$s2, v
	sll	$s3, $s0, 2        # R[$s3] = i << 2 = i * 4 
	add	$s3, $s3, $s2      # R[$s3] = R[$s3] + v = (i * 4) + v
	lw	$s4, ($s3)
	mul	$s4, $s4, 2
	sw	$s4, ($s3)
inc:	addi	$s0, $s0, 1
	b	cond
end:
