#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
listint_t *current;
int A[99999], i = 0, j;

if (head == NULL)
return (1);

current = *head;

while (current)
{
A[i] = current->n;
current = current->next;
i++;
}
i--;

for (j = 0; j <= i; ++j)
{
if (A[i] != A[j])
return (0);
i--;
}
return (1);
}
