#include "monty.h"
/**
  * pchar - print character
  *
  * @stack: stack provided
  * @line_number: line number where error occured
  */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	(void) line_number;
	value = (*stack)->n;
	putchar(value);
	putchar('\n');

}
