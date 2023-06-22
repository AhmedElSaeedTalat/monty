#include "monty.h"
/**
  * swap - swap values in stack
  *
  * @stack: stack provided
  *
  * @line_number: line number where error occurs
  */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next1, *next2;
	char str[1050];

	if (check_size(*stack) < 2 || *stack == NULL)
	{

		sprintf(str, "%d", line_number);
		write(STDERR_FILENO, "L", 1);
		write(STDERR_FILENO, str, strlen(str));
		write(STDERR_FILENO, ": can't swap, stack too short\n", 30);
		exit(EXIT_FAILURE);
	} else if (check_size(*stack) > 2)
	{
		next1 = (*stack)->next;
		next2 =  (*stack)->next->next;
		next1->next = *stack;
		next1->prev = NULL;
		(*stack)->prev = next1;
		(*stack)->next = next2;
		next2->prev = *stack;
		*stack = next1;
	} else if (check_size(*stack) == 2)
	{
		next1 = (*stack)->next;
		next1->next = *stack;
		next1->prev = NULL;
		(*stack)->next = NULL;
		(*stack)->prev = next1;
		*stack = next1;
	}


}
