#!bin/bash

if [ $2 ] ; then
	FLAG="-fsanitize=address"
fi

if [ ! $1 ]; then
	echo "expecting BUFFER_SIZE as parameter 1"
else
	gcc -Wall -Werror -Wextra $FLAG -D BUFFER_SIZE=$1 ../get_next_line/*.c main_romeu.c && ./a.out
	rm a.out
fi