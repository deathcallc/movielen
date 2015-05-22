#!/bin/sh
var="./$1"

mkdir ./$1

cp "EigenVector" "$var"
cp "eigenvalues" "$var"
cp "matrix" "$var"
cp "submatrix" "$var"

