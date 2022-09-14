#include "monty.h"
/**
 * push - adds a new node at the beginning of a dlistint_t list
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line_number of instruction
 * Return: address of new element
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *newnode = NULL;
	int num = 0;
	int result = 1;

	(void)line_number;
	if (helpy.queueflag == 1)
		result = queuepush(&helpy.head, helpy.line_number);
	if (result == 0)
		return;
	if (!head)
	{
		free_everything();
		exit(1);
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_everything();
		exit(EXIT_FAILURE);
	}
	num = atoi(helpy.token2);
	newnode->n = num;
	newnode->prev = NULL;
	newnode->next = NULL;
	if (!*head)
	{
		*head = newnode;
		return;
	}
	newnode->next = *head;
	(*head)->prev = newnode;
	*head = newnode;
}

/**
 * pall - prints all the elements of a stack_t list
 * @head: pointer to a struct of type stack_t
 * @line_number: line number of instruction
 * Return: number of nodes
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	(void)line_number;

	while (*head)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
	*head = tmp;
}
/**
 * free_dlistint - free a dlistint_t list
 * @head: pointer to stack_t struct
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp = NULL;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
/**
 * pint - prints first element of a dlistint_t list
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 * Return: void
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (*head)
		printf("%d\n", (*head)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
}
/**
 * sw - swaps the top two elements of the stack
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 * Return: void
 */
void sw(stack_t **head, unsigned int line_number)
{
	int tmp;
	stack_t *current = *head;
	int counter = 0;

	while (current)
	{
		counter++;
		current = current->next;
	}
	if (counter < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
