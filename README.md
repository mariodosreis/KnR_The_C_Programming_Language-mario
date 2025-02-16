# K&R's The C Programming Language

The examples and exercises of The C Programming Language, by B. W. Kernighan and D. M. Ritchie, 2nd edition, Prentice Hall, provided as I go along.

Note K&D's book is written using ANSI C (a.k.a. c89). To compile the examples you need to specify the c89 standard. For example, to compile the `hello.c` example:

```
cd 1/1.1
cc -std=c89 hello.c
```

This generates file `a.out`, which can be run 

```
./a.out
```

to print its famous output:

```
hello, world
```

