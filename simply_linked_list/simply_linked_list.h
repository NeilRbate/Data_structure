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
 * Dependencies : stdlib, stdio (malloc + perror), NULL define
 * Use for create the first element of the list
 * -Return NULL and perror if they are some issues
 * -Return ptr to the element was created is everything is ok
*/
s_list	*s_list_create(void *data);

//--Addlast func--//
/*
 * Dependencies : s_list_golast, s_list_create, stdlib, stdio
 * Use for add a node at the end of list
 * Return NULL and print on stderr if they are some issues
 * Return ptr to the last element if everything is ok
*/
s_list	*s_list_addlast(s_list *list, void *data);

//--Addfront func--//
/*
 * Take care, this function add and elem before the (*list elem),
 * if its not the first elem, you can definitly lost the data before
 * this element.
 * Dependencies : stdio, stdlib, stderr, s_list_create
 * Use for add and element at the top of the list
 * Return NULL and print on stderr if they are an issues
 * Return ptr to the new first element of the list if its ok
*/
s_list	*s_list_addfront(s_list *list, void *data);

//--Golast func--//
/*
 * Dependencies : stdio, stderr
 * Use for go to the last element of the list and return them
 * Return NULL and print on stderr if they are some issues
 * Return ptr on the last element if everything is ok
*/
s_list	*s_list_golast(s_list *list);

//--Size func--//
/*
 * Dependencies : stdio
 * This function is used for know the nb of elem on the list
 * The fucntion start count from the elem you pass, take care
 * Return -1 and printf on stderr if they are an issue
 * Return the size if everthing is ok
*/
int	s_list_size(s_list *list);
#endif
