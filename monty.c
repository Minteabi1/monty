#include "monty.h"
helpers helpy;
/**
 * main - runs the monty program
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	helpy.n = 0;
	helpy.line_number = 0;
	helpy.token1 = NULL;
	helpy.head = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	helpy.fp = fopen(argv[1], "r");
	if (helpy.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	montyprocess();
	free_everything();
	return (0);
}
