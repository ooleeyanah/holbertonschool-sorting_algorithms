#include "sort.h"
/**
 * insertion_sort_list - insertion sort double link asc
 * @list: pointer to head
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *insert, *tmp;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
current = (*list)->next;
while (current)
{
insert = current;
current = current->next;
while (insert->prev && insert->n < insert->prev->n)
{
tmp = insert->prev;
tmp->next = insert->next;
if (insert->next)
insert->next->prev = tmp;
insert->prev = tmp->prev;
insert->next = tmp;
if (tmp->prev)
tmp->prev->next = insert;
else
*list = insert;
tmp->prev = insert;
print_list(*list);
}
}
}
