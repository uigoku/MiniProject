#include<stdio.h>
#include<stdlib.h>

#include"tree.h"

tree initTree(void *data){
	tree *node = (tree *)malloc(sizeof(tree));
	
	//check whether mallloc successful or not
	if(node == NULL){
		printf("Memory allocation failed\n");
		return NULL
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
