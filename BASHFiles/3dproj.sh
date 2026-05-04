#!/usr/bin/env bash


#making a bash file that can be interpretted as a bmp(bitmap) file


height=2
width=2



num_planes=1
bits_per_pixel=24
bytes_per_pixel=$((bits_per_pixel / 8))


#bmp file structure 
#Header -> 14 bytes
	#signature
	printf 'BM'


	#filesize

	#reserved 
	
	#dataoffset

#

