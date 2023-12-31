#include "monty.h"
/**
  * mul - mul top to elements
  * @stack: stack provided
  *
  * @line_number: line number where error occurs
  */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *next1, *ptr;
	int res = 0;

	(void) line_number;
	ptr = *stack;
	next1 = (*stack)->next;
	res = (*stack)->n * next1->n;
	next1->n = abs(res);
	next1->prev = NULL;
	*stack = next1;
	free(ptr);
}
