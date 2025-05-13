# K&R's The C Programming Language

The examples and exercises of The C Programming Language, by B. W. Kernighan and
D. M. Ritchie, 2nd edition, Prentice Hall, provided as I go along.

Note K&R's code is written using ANSI C (i.e. C89). To compile the examples
you need to specify the ANSI standard. For example, to compile the `hello.c`
example:

```
cd 1/1.1
cc -ansi hello.c
```

This generates file `a.out`, which can be run

```
./a.out
```

to print its famous output:

```
hello, world
```

You can use `Mary.txt` to test code that requires character input:

```
cd 1/1.5/1.5.1
cc -std=c89 copyio.c
./a.out < ../../../Mary.txt
```

> [!WARNING]
> The code in this repository is released as is, without any guarantee that it
> is correct or useful for anything.
