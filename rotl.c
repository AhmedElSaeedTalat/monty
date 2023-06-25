#include "monty.h"
/**
  * rotl - Entry point
  *
  * @stack: stack provided
  * @line_number: where error occured
  */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *temp;
	(void) line_number;

	node = *stack;
	while (node != NULL)
	{
		temp = node->next;
		node->next = node->prev;
		node->prev = temp;
		node = temp;
		if (node != NULL && node->next == NULL)
			*stack = node;
	}
}
