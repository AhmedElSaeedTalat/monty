#include "monty.h"
/**
  * pchar_error - check erros
  *
  * @stack: stack provided
  * @f: file provided
  * @line_number: line number where error occured
  */
void pchar_error(stack_t *stack, FILE *f, int line_number)
{
	char str[1050];

	if (stack == NULL || check_size(stack) == 0)
	{
		sprintf(str, "%d", line_number);
		write(STDERR_FILENO, "L", 1);
		write(STDERR_FILENO, str, strlen(str));
		write(STDERR_FILENO, ": can't pchar, stack empty\n", 27);
		fclose(f);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else if (stack->n < 0 || stack->n > 127)
	{
		sprintf(str, "%d", line_number);
		write(STDERR_FILENO, "L", 1);
		write(STDERR_FILENO, str, strlen(str));
		write(STDERR_FILENO, ": can't pchar, value out of range\n", 34);
		fclose(f);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
