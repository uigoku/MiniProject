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
