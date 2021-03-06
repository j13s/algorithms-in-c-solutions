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

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct thing Item;
typedef struct node *link;

struct thing {
    int num;
};

struct node {
    Item item;
    link next;
};

link create_node();
link insert_after(link, link);
link make_nodes(int);

link circ_make_nodes(int);
void circ_free_nodes(link);

link make_nodes(int);
void free_nodes(link);
#endif  /* LINKEDLIST_H */
