#include "monty.h"
/**
  * redirect - redirect based on function
  *
  * @str: recieved action to call
  *
  * Return: pointer to the function
  */
void (*redirect(char *str))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"dv", dv},
		{"mul", mul},
		{"nop", nop},
		{NULL, NULL}
	};
	for (i = 0; inst[i].opcode != NULL; i++)
	{
		if (strcmp(inst[i].opcode, str) == 0)
			return (inst[i].f);
	}
	return (NULL);
}
