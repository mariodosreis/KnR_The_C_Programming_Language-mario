#! /bin/bash

cc -ansi Exercise.7-1.c
cc -ansi Exercise.7-1.c -o lower
cc -ansi Exercise.7-1.c -o upper

# exits with error:
./a.out <../../Mary.txt
echo ""
# converts to lower case:
./lower <../../Mary.txt
echo ""
# converts to upper case:
./upper <../../Mary.txt

# clean up:
rm a.out lower upper
