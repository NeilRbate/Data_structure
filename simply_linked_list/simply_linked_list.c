#include "simply_linked_list.h"

//--Create func--//
s_list	*s_list_create(void *data) {
	
	s_list	*list;
	if (!(list = malloc(sizeof(*list)))) {
				
		perror("s_list");
		return (NULL);
	}
	list->next = NULL;
	list->data = NULL;
	if (data)
		list->data = data;
	return (list);
}	
//--Addlast func--//
s_list	*s_list_addlast(s_list *list, void *data) {

	s_list	*next, *last;

	if (!(last = s_list_golast(list)))
		return (NULL);
	if (!(next = s_list_create(data)))
		return (NULL);
	last->next = next;
	return (next);
}

//--Golast func--//
s_list	*s_list_golast(s_list *list) {

	if (!list) {
		fprintf(stderr, "error: NULL value find in s_list_golast function\n");
		return (NULL);
	}
	while (list->next)
		list = list->next;
	return  (list);
}




