#include "monty.h"
/**
  * pop_error - check if stack is empty
  *
  * @stack: stack provided
  *
  * @line_number: line_number where error occurs
  * @f: file opened provided to close
  */
void pop_error(stack_t *stack, FILE *f, int line_number)
{
	char str[1050];

	if (stack == NULL)
	{
		sprintf(str, "%d", line_number);
		write(STDERR_FILENO, "L", 1);
		write(STDERR_FILENO, str, strlen(str));
		write(STDERR_FILENO, ": can't pop, stack empty\n", 25);
		fclose(f);
		exit(EXIT_FAILURE);
	}
}
/**
  * pop - pop first element in the stack
  *
  * @stack: stack provided
  *
  * @line_number: line_number where error occurs
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void) line_number;
	ptr = *stack;
	if (check_size(*stack) == 1)
	{
		free(ptr);
		*stack = NULL;
	} else
	{
		(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		free(ptr);
	}
}
