typedef struct tree{
	void *data;
	struct tree *root;
	
	struct tree *next, *prev;
	struct tree *first, *actual, *last;
} tree;

tree *initTree(void *data);
