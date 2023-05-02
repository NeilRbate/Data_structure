#ifndef SIMPLY_LINKED_LIST
#define SIMPLY_LINKED_LIST

//--For malloc--//
#include <stdlib.h>
//--For printf--//
#include <stdio.h>

//--List struct--//
typedef struct	list {

	void		*data;
	struct list	*next;

}		s_list;

//--Create func--//
/*
 * Use for create the first element of the list
 * -Return NULL and perror if they are some issues
 * -Return ptr to the element was created is everything is ok
*/
s_list	*s_list_create(void *data);

//--Addlast func--//
/*
 * Use for add a node at the end of list
 * Return NULL and print on stderr if they are some issues
 * Return ptr to the last element if everything is ok
*/
s_list	*s_list_addlast(s_list *list, void *data);

//--Golast func--//
/*
 * Use for go to the last element of the list and return them
 * Return NULL and print on stderr if they are some issues
 * Return ptr on the last element if everything is ok
*/
s_list	*s_list_golast(s_list *list);

#endif
