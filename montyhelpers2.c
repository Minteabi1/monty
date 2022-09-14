#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 *
 * Return: void
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!*head)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
	if (*head)
		(*head)->prev = NULL;
}
/**
 * add - adds top two elements of stack
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 *
 * Return: void
 */
void add(stack_t **head, unsigned int line_number)
{
	int sum = 0;
	int counter = 0;
	stack_t *current = *head;
	stack_t *tmp = NULL;

	while (current)
	{
		counter++;
		current = current->next;
	}
	if (counter < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	sum += (*head)->n;
	sum += (*head)->next->n;
	tmp = *head;
	(*head)->next->n = sum;
	*head = (*head)->next;
	free(tmp);
	(*head)->prev = NULL;
}
/**
 * nop - doesn’t do anything
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 *
 * Return: void
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
