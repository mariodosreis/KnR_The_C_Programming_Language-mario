/* use typedef to define tree structure and print them nicely out */

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode *Treeptr;

typedef struct tnode {
  char *word;
  Treeptr left;
  Treeptr right;
} Treenode;

Treeptr talloc(int n);
void printtree(Treeptr root);

main()
{
  /* allocate memory for tree of five nodes */
  Treeptr apes = talloc(5);

  /* construct tree */
  apes[0].left = &apes[1];    /* Human-Chimp ancestor */
  apes[0].right = &apes[2];   /* Gorilla */
  apes[1].left = &apes[3];    /* Human */
  apes[1].right = &apes[4];   /* Chimp */

  /* these are tips with no offspring */
  apes[2].left = NULL;
  apes[2].right = NULL;
  apes[3].left = NULL;
  apes[3].right = NULL;
  apes[4].left = NULL;
  apes[4].right = NULL;

  /* set names */
  apes[0].word = "";
  apes[1].word = "";
  apes[2].word = "Gorilla";
  apes[3].word = "Human";
  apes[4].word = "Chimp";

  printtree(apes);

  printf("\n");

  return 0;
}

/* talloc: allocate n Treenode's */
Treeptr talloc(int n)
{
  return (Treeptr) malloc(sizeof(Treenode) * n);
}

/* printtree: print tree in parenthetic format */
void printtree(Treeptr p)
{
  if (p != NULL) {
    if (p->left != NULL && p->right != NULL) {
      printf("(");
      printtree(p->left);
      printf(",");
      printtree(p->right);
      printf(")");
    }
    printf("%s", p->word);
  }
}
