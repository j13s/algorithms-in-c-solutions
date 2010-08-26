/* Copyright 2010 James Kastrantas.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * Sedgewick, R. (1998). Algorithms in C (3rd ed.).
 * Reading, MA: Addison Wesley.
 *
 * Exercise 3.27:
 * Given pointers x and t to nodes on a circular list, write a code fragment
 * that moves the node following t to the position following the node
 * following x on the list.
 */

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"


int main(int argc, char **argv) {
    const int num_nodes = 100;
    link  list,
          x, x1, x2,
          t, t1, t2;
    int   nt = atoi(argv[1]),
          nx = atoi(argv[2]),
          i;
    
    
    list = x = t = circ_make_nodes(num_nodes);
    
    link l = x;
    for (i = 0; i < num_nodes; i++) {
        l->item.num = i;
        l = l->next;
    }
    
    for (i = 0; i < nt; i++) {
        t = t->next;
    }
    for (i = 0; i < nx; i++) {
        x = x->next;
    }
    
    
    /* Solution for 3.27. */
    /* Don't do anything if the node will just be moved to the same place.  If
       x = 99 and t = 0, then the node after t (1) will be moved two places
       after 99 to position 1.  It is easier not to do anything if this
       condition is met. */
    if (x->next != t) {
        x1 = x->next;
        x2 = x1->next;
        
        t1 = t->next;
        t2 = t1->next;

        t->next = t2;
        
        x1->next = t1;
        t1->next = x2;
    }
    
    l = list;
    for (i = 0; i < num_nodes; i++) {
        printf("%d: %d\n", i, l->item.num);
        
        l = l->next;
    }
    
    circ_free_nodes(list);
    
    return (0);
}
