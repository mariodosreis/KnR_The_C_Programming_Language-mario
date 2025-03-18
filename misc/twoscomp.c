#include <stdio.h>

/* 32-bit representation of +11:
 * 0000 0000 0000 0000 0000 0000 0000 1011 (0xB)
 *
 * Two's complement representation of -11:
 * * first invert +11 representation:
 * 1111 1111 1111 1111 1111 1111 1111 0100 (0xFFFFFFA)
 * * then add one:
 * 1111 1111 1111 1111 1111 1111 1111 0101 (0xFFFFFF5)
*/

main()
{
    unsigned i = 11;
    printf("%d\n", ~i + 1);
    printf("%x\n", i);
    printf("%x\n", ~i + 1);
    /* Assumming 32 bit ints: */
    printf("%d\n", 0xB);
    printf("%d\n", 0xFFFFFFF5);

    return 0;
}
