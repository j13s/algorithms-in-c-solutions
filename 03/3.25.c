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
 * Exercise 3-25:
 * Write a code fragment that determines the number of nodes that are between
 * the nodes referenced by two given pointers x and t to nodes on a circular
 * list.
 */

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int main(int argv, char **argc) {
    const int num_links = 100000;
    link  first_link    = circ_make_nodes(num_links),
          x,
          t;
    int   num_x    = atoi(argc[1]),
          num_t    = atoi(argc[2]),
          distance = 0;
    
    
    x = t = first_link;
    
    if (argv == 0) {
        printf ("To find the distance of two nodes in a linked list, please "
               "enter two numbers.\n");
        
        exit(3);
    }
    else if (num_x < 0) {
        printf("First argument (%d) is less than zero.  Enter a number zero or "
               "higher, up to %d.\n", num_x, num_links);
        
        exit(1);
    }
    else if (num_t > num_links - 1) {
        printf("Second argument (%d) is greater than %d.  Enter a number "
               "that is less than or equal to %d.\n",
               num_t,
               (num_links - 1),
               (num_links - 1)
        );
        
        exit(2);
    }
    
    
    for (int j = 0; j < num_x; j++) {
        x = x->next;
    }
    
    for (int j = 0; j < num_t; j++) {
        t = t->next;
    }    
    
    /* This do-while loop is the solution to Exercise 3.25. */
    do {
        distance++;
    } while ((x = x->next) != t);
    
    printf("Distance between nodes %d and %d is %d.\n",
           num_x,
           num_t,
           distance
    );
    
    circ_free_nodes(first_link);
    
    return (0);
}
