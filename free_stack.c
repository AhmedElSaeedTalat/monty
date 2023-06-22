#include "monty.h"
/**
  * free_stack - frees the stack
  *
  * @stack: stack provided to free
  */
void free_stack(stack_t *stack)
{
	stack_t *curr, *ptr;

	if (stack == NULL)
		return;
	curr = stack;
	while (curr != NULL)
	{
		ptr = curr;
		curr = curr->next;
		free(ptr);
	}
}
