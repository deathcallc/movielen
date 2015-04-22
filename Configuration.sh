#!/bin/sh

cd ../Date/

path=`pwd`

for file in *
do
	echo "$path/$file"
done

echo "$path"
