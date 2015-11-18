/*   This a simple version of the arcade game tron
   Copyright (C) 2015  Aditya Karamchandani
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
   
*/

#ifndef __TREE_H__
#define __TREE_H__

typedef struct tree{
	void *data;
	struct tree *root;
	
	struct tree *next, *prev;
	struct tree *first, *actual, *last;
} tree;

extern tree *treenew(void *data);

extern tree *treeaddfirst(tree *node, tree *data);

extern tree *push(tree *node, void *data);

extern tree *pop(tree *node);

extern tree *rem(tree *item);

extern void deltree(tree *node);

extern void delnodes(tree *node);

extern void (*datafree)(void*);

#endif
