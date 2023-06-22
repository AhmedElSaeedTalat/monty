#include "monty.h"
/**
  * redirect_errors - redirect errors
  *
  * @f: file provided to close
  * @counter: line number of file
  * @lowered: command
  * @stack: stack provided
  */
void redirect_errors(char *lowered, FILE *f, int counter, stack_t **stack)
{
	if (_cmp1(lowered))
		check_addError(f, stack, counter, lowered);
	else if (strcmp(lowered, "pop") == 0)
		pop_error(*stack, f, counter);
	else if (strcmp(lowered, "pchar") == 0)
		pchar_error(*stack, f, counter);
}
