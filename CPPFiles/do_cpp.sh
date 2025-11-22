#!/bin/bash

outname="${1%.*}"

g++ "$1" -o "$outname" && ./"$outname"
