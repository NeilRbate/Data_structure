#include "doubly_linked_list.h"

//--Create func--//
d_list	*
d_list_create(void *data) {

	d_list	*current;
	if (!(current = malloc(sizeof(*current)))) {
		perror("d_list");
		return (NULL);
	}
	current->next = NULL;
	current->prev = NULL;
	current->data = NULL;
	if (data)
		current->data = data;
	return (current);
}

//--Addlast func--//
d_list	*
d_list_addlast(d_list *current, void *data) {

	d_list	*new, *last;

	if (!current) {
		fprintf(stderr, "error: Null value send to d_list_addlast function\n");
		return (NULL);
	}
	if (!(last = d_list_golast(current)))
		return (NULL);
	if (!(new = d_list_create(data)))
		return (NULL);
	last->next = new;
	new->prev = last;
	new->next = NULL;
	return (new);
}

//--Addfront func--//
d_list	*
d_list_addfront(d_list *current, void *data) {

	d_list	*new, *first;

	if (!current) {
		fprintf(stderr, "error: Null value send to d_list_addfront function\n");
		return (NULL);
	}
	if (!(first = d_list_gofirst(current)))
		return (NULL);
	if (!(new = d_list_create(data)))
		return (NULL);
	first->prev = new;
	new->next = first;
	return (new);
}

//--Insert func--//
d_list	*
d_list_insert(d_list *current, d_list *new) {

	d_list	*next;

	if (!current || !new) {
		fprintf(stderr, "error: Null value send to d_list_insert function\n");
		return (NULL);
	}
	next = current->next;
	if (!next) {
		current->next = new;
		new->prev = next;
		return (new);
	}
	next->prev = new;
	current->next = new;
	new->prev = current;
	new->next = next;
	return (new);
}

//--Golast func--//
d_list	*
d_list_golast(d_list *current) {

	if (!current) {
		fprintf(stderr, "error: Null value send to d_list_golast function\n");
		return (NULL);
	}
	while (current->next)
		current = current->next;
	return (current);
}
		
//--Gofirst func--//
d_list	*
d_list_gofirst(d_list *current) {

	if (!current) {
		fprintf(stderr, "error: Null value send to d_list_gofirst function\n");
		return (NULL);
	}
	while (current->prev)
		current = current->prev;
	return (current);
}

//--Size func--//
int
d_list_size(d_list *current) {

	int	size = 1;

	if (!current) {
		fprintf(stderr, "error: Null value send to d_list_size function\n");
		return (-1);
	}
	while (current->next) {
		current = current->next;
		size++;
	}
	return (size);
}

//--Free func--//
void
d_list_free(d_list *current) {

	d_list	*stock;

	if (!current) {
		fprintf(stderr, "error: Null value send to d_list_free function\n");
		return ;
	}
	while (current->next) {
		stock = current;
		current = current->next;
		if (stock->data) {
			free(stock->data);
			stock->data = NULL;
		}
		free(stock);
		stock = NULL;
	}
	free(current->data);
	current->data = NULL;
	free(current);
	current = NULL;
}



