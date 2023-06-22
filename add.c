#include "monty.h"
/**
  * check_addError - check if stack is empty or is 1 element
  *
  * @stack: stack provided
  *
  * @f: file opened to close
  *
  * @line_number: line number where error occurs
  * @lowered: pointer passed
  */
void check_addError(FILE *f, stack_t **stack, int line_number, char *lowered)
{
	char str[1050];

	if (*stack == NULL || check_size(*stack) < 2)
	{
		sprintf(str, "%d", line_number);
		write(STDERR_FILENO, "L", 1);
		write(STDERR_FILENO, str, strlen(str));
		if (strcmp(lowered, "add") == 0)
			write(STDERR_FILENO, ": can't add, stack too short\n", 29);
		else if (strcmp(lowered, "sub") == 0)
			write(STDERR_FILENO, ": can't sub, stack too short\n", 29);
		else if (strcmp(lowered, "dv") == 0)
			write(STDERR_FILENO, ": can't div, stack too short\n", 29);
		else if (strcmp(lowered, "mul") == 0)
			write(STDERR_FILENO, ": can't mul, stack too short\n", 29);
		fclose(f);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0 && strcmp(lowered, "dv") == 0)
	{
		sprintf(str, "%d", line_number);
		write(STDERR_FILENO, "L", 1);
		write(STDERR_FILENO, str, strlen(str));
		write(STDERR_FILENO, ": division by zero\n", 19);
		fclose(f);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
  * add - add top to elements
  * @stack: stack provided
  *
  * @line_number: line number where error occurs
  */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *next1, *ptr;
	int sum = 0;

	(void) line_number;
	ptr = *stack;
	next1 = (*stack)->next;
	sum = (*stack)->n + next1->n;
	next1->n = sum;
	next1->prev = NULL;
	*stack = next1;
	free(ptr);
}
