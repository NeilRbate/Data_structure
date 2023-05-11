#ifndef BINARY_TREE
# define BINARY_TREE

//--For printf--//
#include <stdlib.h>
//--For printf--//
#include <stdio.h>

typedef struct	s_node {

	int		key;
	void		*data;
	struct s_node	*left;
	struct s_node	*right;
}		t_node;


//--Create func--//
/*
 *
 *
 *
 *
 */
t_node	*
t_node_create(int key, void *data);

#endif
