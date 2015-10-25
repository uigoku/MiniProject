#include<stdio.h>
#include<stdlib.h>

#include"tree.h"

void (*datafree)(void*) = free

tree treenew(void *data){
	tree *node = (tree *)malloc(sizeof(tree));
	
	//check whether mallloc successful or not
	if(node == NULL){
		printf("Memory allocation failed\n");
		return NULL;
	}
	
	//initialize all pointers to NULL
	node->root = NULL;
	node->next = NULL;
	node->prev = NULL;
	node->first = NULL;
	node->actual = NULL;
	node->last = NULL;
	
	node->data = data;
}

tree *treeaddfirst(tree *node, tree *data){
	if(node == NULL || data == NULL)
		return NULL;
	
	rem(data);
	data->root = node;
	data->prev = NULL;

	data->next = node->first;

	if (node->first == NULL) {
		node->last = data;
		node->actual = data;
	} else
		node->first->prev = data;
	node->first = data;

	return data;
	
}

tree *push(tree *node, void *data){
	
	return treeaddfirst(node, treenew(data));
}

tree *pop(tree *node){
	
	tree *p;
	
	if (node == NULL || node->first == NULL)
		return NULL;

	p = node->first;
	node->first = p->next;
	if (node->first == NULL)
		node->last = NULL;
	else
		node->first->prev = NULL;
	if (node->actual == p)
		node->actual = node->first;
	p->root = NULL;

	return p;
}

tree *rem(tree *item){
	
	tree *node;
	
	if (item == NULL)
		return NULL;

	node = item->root;
	if (node == NULL)
		return item;

	if (item->next == NULL) {
		node->last = item->prev;
	} else
		item->next->prev = item->prev;

	if (item->prev == NULL) {
		node->first = item->next;
	} else
		item->prev->next = item->next;
	
	if (item == node->actual) {
		if (item->next != NULL)
			node->actual = item->next;
		else
			node->actual = item->prev;
	}
	item->root = NULL;
	item->next = NULL;
	item->prev = NULL;

	return item;
}

void deltree(tree *node){
	
	if(node == NULL)
		return ;

	datafree(node->data);

	rem(node);
	while (node->first != NULL) {
		deltree(node->first);
	}
	tree_del(node->next);

	free(node);
}

void delnodes(tree *node){
	
	if(node == NULL)
		return;
	while (node->first != NULL)
		deltree(node->first);
}
