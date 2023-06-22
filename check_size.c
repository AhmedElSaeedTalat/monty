#include "monty.h"
/**
  * check_size - checks the size of the list
  *
  * @stack: stack provided
  *
  * Return: counter for number of nodes
  */
int check_size(stack_t *stack)
{
	int counter;
	stack_t *curr;

	curr = stack;
	counter = 0;
	if (stack == NULL)
		return (0);
	while (curr != NULL)
	{
		curr = curr->next;
		counter++;
	}
	return (counter);
}
