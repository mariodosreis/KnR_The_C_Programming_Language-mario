/* Exercise 7-6. Write a program to compare two files, printing the first line
 * where they differ. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINESIZE 100

main(int argc, char *argv[])
{
  char *prog = argv[0];

  if (argc != 3) {
    fprintf(stderr, "Usage: %s foo1 foo2\n", prog);
    exit(1);
  }

  FILE *fp1, *fp2;
  if ((fp1 = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "%s: could not open %s for reading\n", prog, argv[1]);
    exit(2);
  }
  if ((fp2 = fopen(argv[2], "r")) == NULL) {
    fprintf(stderr, "%s: could not open %s for reading\n", prog, argv[2]);
    exit(2);
  }

  int n = LINESIZE;
  char line1[n];
  char line2[n];

  while (fgets(line1, n, fp1) != NULL && fgets(line2, n, fp2) != NULL)
  {
    if (strcmp(line1, line2) != 0) {
      printf("%s:\n%s\n", argv[1], line1);
      printf("%s:\n%s\n", argv[2], line2);
      exit(0);
    }
  }
  exit(0);
}
