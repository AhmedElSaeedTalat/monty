#include "monty.h"
/**
  * _cmp - chcek if instruction is valid
  *
  * @lowered: instruction command passed
  *
  * Return: 1 if true as valid 0 if false as command not valid
  */
int _cmp(char *lowered)
{
	int i;
	char *dict[12] = {"add", "sub", "push", "swap", "pall",
		"nop", "pop", "pint", "div", "mul", "mod", NULL};

	for (i = 0; dict[i] != NULL; i++)
	{
		if (strcmp(lowered, dict[i]) == 0)
			return (1);
	}
	return (0);
}
