#include "monty.h"
/**
  * pstr - prints the string starting at the top of the stack
  *
  * @stack: stack provided
  * @line_number: where error occured
  */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void) line_number;
	if (*stack == NULL || check_size(*stack) == 0)
		return;
	curr = *stack;
	while (curr != NULL)
	{
		if (curr->n < 0 || curr->n > 127)
		{
			curr = curr->next;
			continue;
		}
		putchar(curr->n);
		curr = curr->next;
	}
	putchar('\n');
}
