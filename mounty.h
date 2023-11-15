#ifndef MOUNTY_H_
#define MOUNTY_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct free_items - items to be freed
 * @fd: file descriptor
 * @buffer: buffer to read in
 *
 * Description: items that should be freed
 * at the end of the program
 */

typedef struct free_items
{
	FILE *fd;
	char *buffer;
} free_items;
extern free_items fr_itm;
void parse_line(stack_t **, unsigned int, int *);
void is_a_number(stack_t **, char *, unsigned int);
void push_operation(stack_t **, int, int);
void push_in_stack(stack_t **, int);
void push_in_queue(stack_t **, int);
void find_ord(stack_t **, char *, unsigned int);
void print_all(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swaps(stack_t **, unsigned int);
void adds(stack_t **, unsigned int);
void subt(stack_t **, unsigned int);
void divi(stack_t **, unsigned int);
void mult(stack_t **, unsigned int);
void modu(stack_t **, unsigned int);
void free_stack(stack_t **);


#endif
