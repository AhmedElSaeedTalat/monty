#include "monty.h"
/**
  * nop - does nothing
  *
  * @stack: stack provided
  *
  * @line_number: line number where error occurs
  */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
