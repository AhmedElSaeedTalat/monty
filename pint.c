#include "monty.h"
/**
  * pint - print element at the top of the stack
  *
  * @stack: stack provided
  *
  * @line_number: where error occurs
  */
void pint(stack_t **stack, unsigned int line_number)
{
	char str[1050];

	if (*stack == NULL)
	{
		sprintf(str, "%d", line_number);
		write(STDERR_FILENO, "L", 1);
		write(STDERR_FILENO, str, strlen(str));
		write(STDERR_FILENO, ": can't pint, stack empty\n", 26);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
