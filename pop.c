#include "monty.h"
/**
  * pop - pop first element in the stack
  *
  * @stack: stack provided
  *
  * @line_number: line_number where error occurs
  */
void pop(stack_t **stack, unsigned int line_number)
{
	char str[1050];
	stack_t *ptr;

	if (*stack == NULL)
	{
		sprintf(str, "%d", line_number);
		write(STDERR_FILENO, "L", 1);
		write(STDERR_FILENO, str, strlen(str));
		write(STDERR_FILENO, ": can't pop, stack empty\n", 25);
		exit(EXIT_FAILURE);
	}
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
