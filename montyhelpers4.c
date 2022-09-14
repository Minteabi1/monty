#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 *
 * Return: void
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	(void)line_number;

	if (!*head)
	{
		putchar('\n');
		return;
	}
	while (current)
	{
		if ((current)->n != 0 && (current)->n >= 0 && (current)->n <= 127)
		{
			putchar((current)->n);
			current = current->next;
		}
		else
			break;
	}
	putchar('\n');
}
/**
 * rotl - rotates the stack to the top
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 *
 * Return: void
 */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *back = *head;
	stack_t *current = *head;
	(void)line_number;
	if (*head && (*head)->next)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		while (current->next)
		{
			current = current->next;
		}
		back->next = current->next;
		back->prev = current;
		current->next = back;
	}
}
/**
 * rotr - rotates the stack to the bottom
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 *
 * Return: void
 */
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *front = NULL;
	stack_t *current = *head;
	(void)line_number;

	if (*head && (*head)->next)
	{
		while (current->next)
			current = current->next;
		current->prev->next = NULL;
		front = current;
		front->next = *head;
		front->prev = NULL;
		*head = front;
	}
}
/**
 * queuepush - adds a new node at the end of a stack_t list
 * @head: pointer to a pointer to a stack_t struct
 * @line_number: number of instruction
 * Return: void
 */
int queuepush(stack_t **head, unsigned int line_number)
{
	stack_t *newnode = NULL;
	stack_t  *current = *head;
	(void)line_number;

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_everything();
		exit(EXIT_FAILURE);
	}
	newnode->n = atoi(helpy.token2);
	newnode->next = NULL;
	newnode->prev = NULL;
	if (!*head)
	{
		newnode->next = *head;
		*head = newnode;
		return (0);
	}
	while (current->next != NULL)
		current = current->next;
	newnode->prev = current;
	current->next = newnode;
	return (0);
}
