#include "simply_linked_list.h"

//--Create func--//
s_list	*
s_list_create(void *data) {
	
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
s_list	*
s_list_addlast(s_list *current, void *data) {

	s_list	*next, *last;

	if (!current) {
		fprintf(stderr, "error: Null value send to s_list_addlast function\n");
		return (NULL);
	}
	if (!(last = s_list_golast(current)))
		return (NULL);
	if (!(next = s_list_create(data)))
		return (NULL);
	last->next = next;
	return (next);
}

//--Addfront func--//
s_list	*
s_list_addfront(s_list *current, void *data) {

	s_list	*new;

	if (!current) {
		fprintf(stderr, "error: Null value send to s_list_addfront function\n");
		return (NULL);
	}
	if (!(new = s_list_create(data)))
		return (NULL);
	new->next = current;
	return (new);
}

//--Insert func--//
s_list	*
s_list_insert(s_list *current, s_list *new) {

	if (!current || !new) {
		fprintf(stderr, "error: Null value send to s_list_insert function\n");
		return (NULL);
	}
	new->next = current->next;
	current->next = new;
	return (current);
}

//--Golast func--//
s_list	*
s_list_golast(s_list *current) {

	if (!current) {
		fprintf(stderr, "error: NULL value send to s_list_golast function\n");
		return (NULL);
	}
	while (current->next)
		current = current->next;
	return  (current);
}

//--Size func--/
int	
s_list_size(s_list *current) {

	int	size = 1;

	if (!current) {
		fprintf(stderr, "error: NULL value send to s_list_size function\n");
		return (-1);
	}
	while (current) {
		size++;
		if (current->next)
			current = current->next;
		else
			return (size);
	}
	return (size);
}

//--Free func--//
void	
s_list_free(s_list *current) {

	s_list	*stock;
	if (!current) {
		fprintf(stderr, "error: Null value send to s_list_free function\n");
		return ;
	}
	while (current) {
		stock = current;
		current = current->next;
		if (stock->data) {
			free(stock->data);
			stock->data = NULL;
		}
		if (stock) {
			free(stock);
			stock = NULL;
		}
	}
}
