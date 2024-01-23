#!/bin/sh

for i in {0..0}; do
    g++ -W -Wall -Wextra -g3 -fsanitize=leak,undefined,address *.cpp "bonus/ex0$i.cpp"
    if  ./a.out | diff "bonus/out0$i.txt" - ; then
        echo "Test $i: OK"
    else
        echo "Test $i: KO"
    fi
done
