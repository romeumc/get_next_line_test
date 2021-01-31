#!bin/bash

# bash run.sh BUFFER_SIZE [anything to sanitize]

if [ $2 ] ; then
	FLAG="-fsanitize=address"
fi

if [ ! $1 ]; then
	echo "expecting BUFFER_SIZE as parameter 1"
else
	echo "gcc -Wall -Werror -Wextra $FLAG -D BUFFER_SIZE=$1 ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c main_romeu.c"	
	gcc -Wall -Werror -Wextra $FLAG -D BUFFER_SIZE=$1 ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c main_romeu.c && ./a.out
	#rm a.out
fi
