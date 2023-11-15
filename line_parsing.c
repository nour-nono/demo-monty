#include "mounty.h"

/**
 * parse_line - parseing_line
 * @head: head
 * @line_number: line of number
 * @mode_stack: mode_stack
 * Return: void
 */

void parse_line(stack_t **head, unsigned int line_number, int *mode_stack)
{
	char *token = strtok(fr_itm.buffer, " \t\n");

	if (token == NULL || token[0] == '\0' || token[0] == '#')
		return;
	if (strcmp("stack", token) == 0 || strcmp("queue", token) == 0)
	{
		if (strcmp("stack", token))
			*mode_stack = 0;
		else
			*mode_stack = 1;
	}
	else if (strcmp("push", token) == 0)
	{
		token = strtok(NULL, " \t\n");
		is_a_number(head, token, line_number);
		push_operation(head, atoi(token), *mode_stack);
	}
	else
	{
		find_ord(head, token, line_number);
	}
}

/**
 * find_ord - find order
 * @head: head
 * @str: string
 * @line_number: line of number
 * Return: void
 */

void find_ord(stack_t **head, char *str, unsigned int line_number)
{
	int i = 0, flag = 0;
	instruction_t order[] = {
		{"pall", print_all},
		{"pint", print_top},
		{"pop", pop_top},
		{"swap", swaps},
		{"add", adds},
		{"sub", subt},
		{"mul", mult},
		{"div", divi},
		{"mod", modu},
		{NULL, NULL}
	};
	for (; order[i].opcode != NULL; ++i)
	{
		if (strcmp(order[i].opcode, str) == 0)
		{
			order[i].f(head, line_number);
			flag = 1;
		}
	}
	if (flag == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}
