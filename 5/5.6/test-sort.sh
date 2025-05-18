#! /usr/bin/bash

# try alloc version of sort:
cc -ansi sort.c

./a.out <../../Mary.txt
seq 100 1 | ./a.out

# repeat Mary 200 times and time the sorting:
time for n in `seq 1 200`; do cat ../../Mary.txt; done | ./a.out >/dev/null

echo "*** Let's crash the sort: ***"
# crash it:
seq 1 5001 | ./a.out

# try non-alloc version of sort:
cc -ansi Exercise.5-7.c

./a.out <../../Mary.txt
seq 100 1 | ./a.out

# repeat Mary 200 times and time the sorting:
time for n in `seq 1 200`; do cat ../../Mary.txt; done | ./a.out >/dev/null
