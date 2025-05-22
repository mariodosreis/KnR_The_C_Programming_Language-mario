# K&R's The C Programming Language

The examples and exercises of The C Programming Language, by B. W. Kernighan and
D. M. Ritchie, 2nd edition, Prentice Hall, provided as I go along.

All the code in this repository was tested with the clang compiler on a Mac OSX
system. Note K&R's code is written using ANSI C (i.e. C89). To compile the
examples you need to specify the ANSI standard, either with the `-ansi` or
`-std=c89` flags. For example, to compile the `hello.c` example:

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

Note some functions defined in the book, such as `getline`, were introduced into
the C standard later than the ANSI standard. Despite this, those functions are
still included (in `stdin.h`, etc.) even when you compile with `-ansi`. Thus, if
you use the definitions in the book of those functions in your code, and you try
to compile with `cc -ansi`, you will get an error due to conflicting function
declarations. You can solve this either by renaming the functions (i.e., use
`getline2` and so on), or, if you want to strictly adhere to the original code
in the book, by compiling with `-D_ANSI_SOURCE`, e.g.:

```
cc -ansi -D_ANSI_SOURCE foo.c
```

Note instructions above refer to the clang compiler. For other compiler you may
need to use different flags.

> [!WARNING]
> The code in this repository is released as is, without any guarantee that it
> is correct or useful for anything.
