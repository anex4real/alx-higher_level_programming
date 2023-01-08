#include "lists.h"

/**
 * palindrome - utility for is_palindrome
 * @top: pointer to a pointer to a singly linked list
 * @next: pointer to a singly linked list
 *
 * Return: integer, 1 if palindrome, else 0
 */
int palindrome(listint_t **top, listint_t *next)
{
	int result = 0;

	if (next == NULL)
		return (1);

	if (palindrome(top, next->next) && ((*top)->n == next->n))
		result = 1;

	*top = (*top)->next;

	return (result);
}

/**
 * is_palindrome - check if a singly linked list is a palindrome
 * @head: linked list double pointer
@@ -8,26 +30,6 @@
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	unsigned int i, l = 0;
	int *p;

	if (current == NULL)
		return (1);
	while (current)
		l++, current = current->next;
	p = malloc(l * sizeof(*p));
	current = *head, i = 0;
	while (current)
		p[i++] = current->n, current = current->next;
	i = 0, l -= 1;
	while (i <= l)
	{
		if (p[i++] != p[l--])
			return (0);
	}
	i = 0;
	free(p);
	return (1);
	return (palindrome(head, *head));
}
