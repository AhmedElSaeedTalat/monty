#include "monty.h"
/**
  * create_stack - create new stack
  *
  * @stack: new stack provided
  * Return: newly created stack
  */
stack_t *create_stack(stack_t *stack)
{
	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
		return (NULL);
	return (stack);
}
