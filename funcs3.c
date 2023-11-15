#include "mounty.h"

/**
 * adds - adds two number
 * @stack: head
 * @line_number: line of number
 * Return: void
 */

void adds(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop_top(stack, line_number);
}
/**
 * subt - sub tow numbers
 * @stack: head
 * @line_number: line of number
 * Return: void
 */

void subt(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop_top(stack, line_number);
}

/**
 * divi - divid two number
 * @stack: head
 * @line_number: line of number
 * Return: void
 */

void divi(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop_top(stack, line_number);
}

/**
 * mult - mult two number
 * @stack: head
 * @line_number: line of number
 * Return: void
 */

void mult(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop_top(stack, line_number);
}

/**
 * modu - modu two number
 * @stack: head
 * @line_number: line of number
 * Return: void
 */

void modu(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop_top(stack, line_number);
}
