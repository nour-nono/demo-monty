#include "mounty.h"

/**
 * print_dlistint - check the code
 * @h: struct
 * Return: Always int.
 */
void print_all(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *i;

	if (!stack || !*stack)
		return;
	i = *stack;
	while (i->next != NULL)
	{
		printf("%d\n", i->n);
		i = i->next;
	}
	printf("%d\n", i->n);
}
void print_top(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
void pop_top(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
void swaps(stack_t **stack, unsigned int line_number)
{
	int tmp;
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = tmp;
}
