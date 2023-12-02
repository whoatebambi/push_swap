#!/bin/zsh
make
cc -c push_swap.c -o push_swap.o
cc push_swap.o libftpush_swap.a -o push_swap
./push_swap 1 2 3
make fclean
rm -f push_swap.o
rm -f push_swap
rm -f a.out