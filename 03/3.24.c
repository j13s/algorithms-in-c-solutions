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
 * Exercise 3-24:
 * Write a function that returns the number of nodes on a circular list, given
 * a pointer to one of the nodes on the list.
 */

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int main() {
    const int num_links = 100000;
    
    /* Initialize the circular linked-list. */    
    link first_link   = create_node(0);
    link current_link = first_link,
         next_link;
    
    /* One node has already been allocated, so start at 1. */
    for (int i = 1; i < num_links; i++) {
        current_link = insert_after(current_link, create_node(i));
    }
    /* Make the linked-list circular. */
    current_link->next = first_link;

    /* Count the number of nodes in a circular linked-list. */
    int num_nodes = 0;
    current_link = first_link;
    do {
        if (num_nodes != current_link->item.num) {
            printf(
                "Node %p has the wrong data.  Expected %d but got %d\n",
                num_nodes,
                current_link->item.num
            );
        }
        
        current_link = current_link->next;
        num_nodes++;
    } while (current_link != first_link);


    /* Free the linked-list. */
    circ_free_nodes(current_link);
        
        
    printf("%d nodes were created.\n", num_nodes);
    
    return (0);
}
