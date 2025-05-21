/* play with unions */

#include <stdio.h>

union u_tag {
  int ival;
  float fval;
  char *sval;
} u;

enum { INT, FLOAT, STRING };

void printu(union u_tag, int);

main()
{
  int utype;

  utype = INT;
  u.ival = 10;
  printu(u, utype);

  utype = FLOAT;
  u.fval = 1.543;
  printu(u, utype);

  utype = STRING;
  u.sval = "hello, world";
  printu(u, utype);

  utype = 1000;
  printu(u, utype);

  return 0;
}

/* printu: print current union member */
void printu(union u_tag u, int utype)
{
  if (utype == INT)
    printf("%d\n", u.ival);
  else if (utype == FLOAT)
    printf("%f\n", u.fval);
  else if (utype == STRING)
    printf("%s\n", u.sval);
  else
    printf("bad type %d in utype\n", utype);
}
