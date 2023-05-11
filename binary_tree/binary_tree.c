#include "binary_tree.h"

//--Create func--//
t_node	*
t_node_create(int key, void *data) {

	t_node	*current;

	if (!(current = malloc(sizeof(*current)))) {
		fprintf(stderr, "error: Malloc fail");
		return (NULL);
	}
	current->data = NULL;
	current->left = NULL;
	current->right = NULL;
	current->key = key;
	if (data)
		current->data = data;
	return (current);
}
