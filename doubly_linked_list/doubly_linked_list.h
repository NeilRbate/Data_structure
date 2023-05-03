#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

//--For malloc--//
#include <stdlib.h>
//--For printf--//
#include <stdio.h>

//--List struct--//
typedef struct	dlist {

	void		*data;
	struct dlist	*next;
	struct dlist	*prev;

}		d_list;

//--Create func--//
/*
 * Dependencies : stdlib, stdio (malloc + perror), NULL define
 * Use for create the first element of the list
 * -Return NULL and perror if they are some issues
 * -Return ptr to the element was created is everything is ok
*/
d_list	*
d_list_create(void *data);

//--Addlast func--//
/*
 * Dependencies : d_list_golast, d_list_create, stdlib, stdio
 * Use for add a node at the end of list
 * Return NULL and print on stderr if they are some issues
 * Return ptr to the last element if everything is ok
*/
d_list	*
d_list_addlast(d_list *current, void *data);

//--Addfront func--//
/*
 * Dependencies : stdio, stdlib, stderr, d_list_create, d_list_gofirst
 * Use for add and element at the top of the list
 * Return NULL and print on stderr if they are an issues
 * Return ptr to the new first element of the list if its ok
*/
d_list	*
d_list_addfront(d_list *current, void *data);

//--Golast func--//
/*
 * Dependencies : stdio, stderr
 * Use for go to the last element of the list and return them
 * Return NULL and print on stderr if they are some issues
 * Return ptr on the last element if everything is ok
*/
d_list	*
d_list_golast(d_list *current);

//--Gofirst func--//
/*
 * Dependencies : stdio, stderr
 * Use to go to the first element of the list and return them
 * Return NULL and printf on stderr if they are some issues
 * Return ptr to the first element if everything is ok
*/
d_list	*
d_list_gofirst(d_list *current);



//*************** TO DO ***************//

//--Size func--//
/*
 * Dependencies : stdio
 * This function is used for know the nb of elem on the list
 * The fucntion start count from the elem you pass, take care
 * Return -1 and printf on stderr if they are an issue
 * Return the size if everthing is ok
*/
//int	
//s_list_size(s_list *current);

//--Insert func--//
/*
 * Dependencies : stdio
 * This function insert a new node after the current node
 * Return NULL if the current or new node is NULL
 * Return ptr to the current node if everything is ok
*/
//s_list	*
//s_list_insert(s_list *current, s_list *new);

//--Free func--//
/*
 * Dependencies : stdio, stdlib
 * This function free data and node from current to NULL value and
 * set them to NULL
 * Take care of the value can be before when you free
*/
//void
//s_list_free(s_list *current);

#endif
