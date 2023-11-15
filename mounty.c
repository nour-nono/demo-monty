#include "mounty.h"

/**
 * main - Entry point
 * @ac: arguments count
 * @av: list of arguments
 * Return: Always 0
 */

free_items fr_itm;

int main(int ac, char **av)
{
	size_t n = 0;
	unsigned int line = 1;
	int mode_stack = 1;
	stack_t *head = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fr_itm.fd = fopen(av[1], "r");
	if (fr_itm.fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&fr_itm.buffer, &n, fr_itm.fd) != -1)
	{
		parse_line(&head, line, &mode_stack);
		++line;
	}
	free_stack(&head);
	return (0);
}
