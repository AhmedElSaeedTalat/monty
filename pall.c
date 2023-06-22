#include "monty.h"
/**
  * pall - displays stack
  *
  * @stack: stack provided
  *
  * @line_number: line number provided
  */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void) line_number;
	if (*stack == NULL)
		return;
	curr = *stack;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
