#include "sort.h"

/**
 * swap_node_forward - Function that swaps nodes from the left(head)
 * @list: A pointer to a pointer of the list
 * @tail: Double pointer to the last node in the list
 * @current: Double pointer to the node to swap right
 *
 * Return: Void
 */
void swap_node_forward(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp;

	temp = (*current)->next;
	if ((*current)->prev != NULL)
		(*current)->prev->next = temp;
	else
		*list = temp;

	temp->prev = (*current)->prev;
	(*current)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *current;
	else
		*tail = *current;
	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
}

/**
 * swap_node_backward - A function that swaps nodes from the right(tail)
 * @list: Double pointer to the linked list
 * @tail: Pointer to the pointer of the last node in the list
 * @current: A double pointer to the node to swap left
 *
 * Return: Nothing
 */
void swap_node_backward(listint_t **list,
		listint_t **tail, listint_t **current)
{
	listint_t *temp;

	temp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = temp;
	else
		*tail = temp;

	temp->next = (*current)->next;
	(*current)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *current;
	else
		*list = *current;

	(*current)->next = temp;
	temp->prev = *current;
	*current = temp;
}

/**
 * cocktail_sort_list - Function that applies cocktail shaker sort algorithm
 *			to sort a doubly linked list in an ascending order
 * @list: A double pointer to the linked list
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current;
	bool swaps_made = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (swaps_made == false)
	{
		swaps_made = true;
		for (current = *list; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_node_forward(list, &tail, &current);
				print_list((listint_t *)*list);
				swaps_made = false;
			}
		}
		for (current = current->prev; current != *list;
				current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node_backward(list, &tail, &current);
				print_list((listint_t *)*list);
				swaps_made = false;
			}
		}

	}
}
