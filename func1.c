#include "mounty.h"

void is_a_number(stack_t **head, char *str, unsigned int line)
{
	unsigned long i = 0;
	
	if (str == NULL || *str == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	if (str[0] == '-')
	{
		if (str[1] == '\0')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
		++i;
	}
	for (; i < strlen(str); ++i)
	{
		if (!isdigit(str[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
	}
}
void push_operation(stack_t **head, int n, int mode_stack)
{
	if (mode_stack)
		push_in_stack(head, n);
	else
		push_in_queue(head, n);
}
void push_in_stack(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
		return;
	}
	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;
}
void push_in_queue(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t)), *ex = *head;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return;
	}
	while (ex->next)
		ex = ex->next;
	ex->next = new_node;
	new_node->prev = ex;
}

void free_stack(stack_t **head)
{
	fclose(fr_itm.fd);
	free(fr_itm.buffer);
	if (head == NULL|| *head == NULL)
		return;

	while ((*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
	*head = NULL;
}
