#include "monty.h"
/**
  * _cmp1 - chcek if instruction is valid
  *
  * @lowered: instruction command passed
  *
  * Return: 1 if true as valid 0 if false as command not valid
  */
int _cmp1(char *lowered)
{
	int i;
	char *dict[11] = {"add", "sub", "div", "mul", NULL};

	for (i = 0; dict[i] != NULL; i++)
	{
		if (strcmp(lowered, dict[i]) == 0)
			return (1);
	}
	return (0);
}
