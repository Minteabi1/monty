#include "monty.h"
/**
 * sub - subtracts top two elements of stack
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 *
 * Return: void
 */
void sub(stack_t **head, unsigned int line_number)
{
	int difference = 0;
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
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	difference = (*head)->next->n - (*head)->n;
	tmp = *head;
	(*head)->next->n = difference;
	*head = (*head)->next;
	free(tmp);
	(*head)->prev = NULL;
}
/**
 * divi - divides second top element by top element of the stack.
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 *
 * Return: void
 */
void divi(stack_t **head, unsigned int line_number)
{
	int quotient = 0;
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
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n",
			line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	quotient = (*head)->next->n / (*head)->n;
	tmp = *head;
	(*head)->next->n = quotient;
	*head = (*head)->next;
	free(tmp);
	(*head)->prev = NULL;
}
/**
 * mul - multiplies second top element by top element of the stack.
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 *
 * Return: void
 */
void mul(stack_t **head, unsigned int line_number)
{
	int product = 0;
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
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	product = (*head)->next->n * (*head)->n;
	tmp = *head;
	(*head)->next->n = product;
	*head = (*head)->next;
	free(tmp);
	(*head)->prev = NULL;
}
/**
 * mod - computes the rest of the division of second top by top element
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 *
 * Return: void
 */
void mod(stack_t **head, unsigned int line_number)
{
	int rest = 0;
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
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n",
			line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	rest = (*head)->next->n % (*head)->n;
	tmp = *head;
	(*head)->next->n = rest;
	*head = (*head)->next;
	free(tmp);
	(*head)->prev = NULL;
}
/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n >= 0 && (*stack)->n <= 127)
	{
		printf("%c\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
}
