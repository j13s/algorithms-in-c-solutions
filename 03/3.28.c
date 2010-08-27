/* This code is a derivative work and does not fall under the GPL.
 *
 * Sedgewick, R. (1998). Algorithms in C (3rd ed.).
 * Reading, MA: Addison Wesley.
 *
 * Exercise 3.28:
 * When building the list, Program 3-9 sets twice as many link values as it
 * needs to because it maintains a circular list after each node is inserted.
 * Modify the program to build the circular list without doing this extra
 * work.
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;
struct node { int item; link next; };
int main(int argc, char *argv[])
  { int i, N = atoi(argv[1]), M = atoi(argv[2]); 
    link t = malloc(sizeof *t), x = t;
    t->item = 1; t->next = t;
    for (i = 2; i <= N; i++)
      { 
        x = (x->next = malloc(sizeof *x));
        x->item = i;
      }
      /* Since t points to the first node created, and x is a link to the last
         node created, linking x to t will make the list circular. */
      x->next = t;
    while (x != x->next)
      {
        for (i = 1; i < M; i++) x = x->next;
        x->next = x->next->next; N--;
      }
    printf("%d\n", x->item);
    
  }
