#include "monty.h"
/**
  * sub - sub top to elements
  * @stack: stack provided
  *
  * @line_number: line number where error occurs
  */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *next1, *ptr;
	int res = 0;

	(void) line_number;
	ptr = *stack;
	next1 = (*stack)->next;
	res = next1->n - (*stack)->n;
	next1->n = res;
	next1->prev = NULL;
	*stack = next1;
	free(ptr);
}
