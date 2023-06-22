#include "monty.h"
/**
  * push_error - prints error in case value not provided
  *
  * @stack: stack provided
  * @line_number: line number for error
  */
void push_error(stack_t *stack, unsigned int line_number)
{
	char str[1050];

	free_stack(stack);
	sprintf(str, "%d", line_number);
	write(STDERR_FILENO, "L", 1);
	write(STDERR_FILENO, str, strlen(str));
	write(STDERR_FILENO, ": usage: push integer\n", 22);
	exit(EXIT_FAILURE);
}
/**
  * push - into stack
  *
  * @line_number: line number for error
  * @stack: stack created to push to
  */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack;

	if (push_value == -1)
		push_error(*stack, line_number);
	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		free_stack(*stack);
		write(STDERR_FILENO, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
	new_stack->n = push_value;
	if (*stack == NULL)
	{
		new_stack->next = NULL;
		new_stack->prev = NULL;
		*stack = new_stack;
	} else
	{
		new_stack->prev = NULL;
		new_stack->next = *stack;
		(*stack)->prev = new_stack;
		*stack = new_stack;
	}
}
