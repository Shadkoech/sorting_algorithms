#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *one, *two, *three, *four;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;

	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			one = current->prev->prev;
			two = current->prev;
			three = current;
			four = current->next;

			two->next = four;
			if (four != NULL)
				four->prev = two;
			three->next = two;
			three->prev = one;

			if (one != NULL)
				one->next = three;

			else
				*list = three; /*if one is NULL then three becomes the head of the list*/

			two->prev = three;
			current = *list;
			print_list(*list);
		}
		current = current->next;
	}
}
