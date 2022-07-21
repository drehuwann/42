#!/bin/sh
echo make clean
make clean
echo make
make
echo ./do_op
./do_op
echo ./do_op 1 + 1
./do_op 1 + 1
echo ./do_op 42amis - --+-20toto12
./do_op 42amis - --+-20toto12
echo ./do_op 1 p 1
./do_op 1 p 1
echo ./do_op 1 + toto3
./do_op 1 + toto3
echo ./do_op toto3 + 4
./do_op toto3 + 4
echo ./do_op foo plus bar
./do_op foo plus bar
echo ./do_op 25 / 0
./do_op 25 / 0
echo ./do_op 25 % 0
./do_op 25 % 0
echo ./do_op 10 - 52
./do_op 10 - 52
