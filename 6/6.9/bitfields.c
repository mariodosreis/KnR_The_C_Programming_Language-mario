/* bit fiddling and bit-fields */

#include <stdio.h>

#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 04

void printbits(unsigned char c);

main()
{
  unsigned char flags = 0;
  printbits(flags);

  /* turn EXTERNAL and STATIC on */
  flags |= EXTERNAL | STATIC;
  printbits(flags);

  /* turn EXTERNAL and STATIC off */
  flags &= ~(EXTERNAL | STATIC);
  printbits(flags);

  if ((flags & (EXTERNAL | STATIC)) == 0)
    printf("EXTERNAL and STATIC are off!\n");

  /* create a nested block to define flags as a bitfield */
  {
    struct {
      unsigned int is_keyword : 1;
      unsigned int is_extern : 1;
      unsigned int is_static : 1;
    } flags;

    flags.is_keyword = 0;
    flags.is_extern = flags.is_static = 1;
    /* print bits */
    putchar(flags.is_keyword + '0');
    putchar(flags.is_extern + '0');
    putchar(flags.is_static + '0');
    putchar('\n');

    flags.is_extern = flags.is_static = 0;
    /* print bits */
    putchar(flags.is_keyword + '0');
    putchar(flags.is_extern + '0');
    putchar(flags.is_static + '0');
    putchar('\n');
  }

  return 0;
}

/* printbits: print bits of c in reverse order */
void printbits(unsigned char c)
{
  do {
    printf("%c", c % 2 + '0');
  } while((c /= 2) > 0);
  printf("\n");
}
