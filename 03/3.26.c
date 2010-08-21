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
 * Exercise 3.26:
 * Write a code fragment that, given pointers x and t to two disjoint circular
 * lists, inserts the list pointed to by t into the list pointed to by x, at
 * the point following x.
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void) {
    const int num_nodes = 100;
    link x      = make_nodes(num_nodes),
         t      = make_nodes(num_nodes),
         x2     = x->next,
         t_last = t;
    int  num    = 0;
    
    x->item.num = num++;
    link l = x2;
    for (num = num_nodes + 1; num < num_nodes * 2; num++) {
        l->item.num = num;
        l = l->next;
    }
    l = t;
    for (num = 1; num < (num_nodes + 1); num++) {
        l->item.num = num;
        l = l->next;
    }
    
    
    /* Get the last node in the list for t. */
    while (t_last->next != NULL) {
        t_last = t_last->next;
    }
    
    /* This is the solution for 3.26. */
    x->next = t;
    t_last->next = x2;
    
    /* This checks the linked-list to make sure the order is correct. */
    l = x;
    for (int i = 0; i < num_nodes * 2; i++) {
        if (l->item.num != i) {
            printf("The node at %p is out of order.  Got %d when expecting "
                   " %d.\n",
                   l,
                   l->item.num,
                   i
            );
            
            exit(1);
        }
        
        l = l->next;
    }
    
    free_nodes(x);
    return (0);
}
