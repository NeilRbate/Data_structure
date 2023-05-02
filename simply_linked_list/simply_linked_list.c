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

	if (!list) {
		fprintf(stderr, "error: Null value send to s_list_addlast function\n");
		return (NULL);
	}
	if (!(last = s_list_golast(list)))
		return (NULL);
	if (!(next = s_list_create(data)))
		return (NULL);
	last->next = next;
	return (next);
}

//--Addfront func--//
s_list	*s_list_addfront(s_list *list, void *data) {

	s_list	*new;

	if (!list) {
		fprintf(stderr, "error: Null value send to s_list_addfront function\n");
		return (NULL);
	}
	if (!(new = s_list_create(data)))
		return (NULL);
	new->next = list;
	return (new);
}

//--Golast func--//
s_list	*s_list_golast(s_list *list) {

	if (!list) {
		fprintf(stderr, "error: NULL value send to s_list_golast function\n");
		return (NULL);
	}
	while (list->next)
		list = list->next;
	return  (list);
}

//--Size func--/
int	s_list_size(s_list *list) {

	int	size = 0;

	if (!list) {
		fprintf(stderr, "error: NULL value send to s_list_size function\n");
		return (-1);
	}
	while (list) {
		size++;
		if (list->next)
			list = list->next;
		else
			return (size);
	}
	return (size);
}
