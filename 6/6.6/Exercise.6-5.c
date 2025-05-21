/* Exercise 6-5. Write a function undef that will remove a name and definition
 * from the table maintained by lookup and install. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {    /* table entry: */
  struct nlist *next;   /* next entry in chain */
  char *name;           /* defined name */
  char *defn;           /* replacement text */
};

#define HASHSIZE 101

/* this creates an array of null pointers */
static struct nlist *hashtab[HASHSIZE];  /* pointer table */

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
struct nlist *undef(char *name);

main()
{
  char name[11];
  char defn[11];
  char lkup[] = "HI";

  struct nlist *np;

  /* install (name, defn) from stdin list */
  while (scanf("%10s %10s", name, defn) != EOF) {
    np = install(name, defn);
    printf("Installed: (%s, %s)\n", np->name, np->defn);
  }

  if ((np = lookup(lkup)) != NULL)
    printf("Found %s associated with %s\n", lkup, np->defn);
  else
    printf("Did not find %s\n", lkup);

  /* remove lkup entry from list */
  if ((np = lookup(lkup)) != NULL) {
    printf("Undefining (%s, %s)\n", np->name, np->defn);
    if (undef(np->name) != NULL) {
      printf("Successfully undefined (%s, %s)\n", np->name, np->defn);
      free(np); /* remember to free to avoid memory leaks */
    }
  }

  /* search for lkup again, which must now be missing */
  if ((np = lookup(lkup)) != NULL)
    printf("Found %s associated with %s\n", lkup, np->defn);
  else
    printf("Did not find %s\n", lkup);

  /* TODO: look somehting up in the filled list */
  return 0;
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np;    /* found */
  return NULL;      /* not found */
}

/* install: put (name, dfn) in hashtab */
struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) {  /* not found */
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval]; /* this sets next to current hashtab value */
    hashtab[hashval] = np;       /* this sets current hashtab to new value */
  } else    /* already there */
    free((void *) np->defn);    /* free previous defn */
  if ((np->defn = strdup(defn)) == NULL)
    return NULL;
  return np;
}

/* undef: remove (name, defn) from hastab */
struct nlist *undef(char *name)
{
  struct nlist *np;
  struct nlist *parent = NULL;

  for (np = hashtab[hash(name)]; np != NULL; np = np->next) {
    if (strcmp(name, np->name) == 0){
      if (parent != NULL) {
        parent->next = np->next;
      } else {
        hashtab[hash(name)] = np->next;
      }
      return np;
    }
    parent = np;
  }
  return NULL;
}
