#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>
#include <sys/stat.h>
#define LIMIT 100
extern int push_value;
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
void read_file(char *file_name);
stack_t *create_stack(stack_t *stack);
void free_stack(stack_t *stack);
void (*redirect(char *str))(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
int check_size(stack_t *stack);
void check_addError(FILE *f, stack_t **stack, int line_number, char *lowered);
void pop_error(stack_t *stack, FILE *f, int line_number);
int _cmp(char *lowered);
int _cmp1(char *lowered);
void sub(stack_t **stack, unsigned int line_number);
void dv(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void redirect_errors(char *lowered, FILE *f, int counter, stack_t **stack);
void pchar_error(stack_t *stack, FILE *f, int counter);
#endif
