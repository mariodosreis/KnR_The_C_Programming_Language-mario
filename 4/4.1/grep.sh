# Compile it and run it
cc -ansi main.c getline.c strindex.c

./a.out <AhLove.txt

# ./a.out returns the number of matches, this is temporarily stored in $?
echo $?
