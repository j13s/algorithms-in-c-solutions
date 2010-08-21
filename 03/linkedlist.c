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
 */

#include "linkedlist.h"
#include <stdlib.h>

link
create_node(int num) {
    link l = (link)malloc(sizeof(struct node));
    
    l->item.num = num;
     
    return l;
}

link
insert_after(link beginning, link end) {
    link middle = beginning->next;
    
    beginning->next = end;
    end->next = middle;
    
    return end;
}

void
circ_free_nodes(link first_link) {
    link current_link = first_link,
         next_link;
    
    do {
        next_link = current_link->next;        
        free(current_link);
        current_link = next_link;
    } while (current_link != first_link);
}
