#!/bin/sh
gcc -Wall -Wextra -Werror -o tst00  main.c -L. -lft
chmod +x ./tst00
./tst00
rm ./tst00
