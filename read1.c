#include "monty.h"
#include <string.h>
int push_value = 0;
/**
  * check_push_value - check if push value provided and if it's valid
  *
  * @token: token received from the file
  *
  * @f: file to close in case of an error
  * Return: 1 if value is valid or 0 if not valid
  */
int check_push_value(char *token, FILE *f)
{
	if (token == NULL)
	{
		fclose(f);
		return (0);
	}
	else if (strcmp(token, "0") != 0)
	{
		if (!atoi(token))
		{
			fclose(f);
			return (0);
		}
	}
	return (1);
}
/**
  * error_instruction - prints error
  *
  * @instruction: instruction provided
  * @line_number: line number for error
  */
void error_instruction(char *instruction, int line_number)
{
	char str[1050];

	sprintf(str, "%d", line_number);
	write(STDERR_FILENO, "L", 1);
	write(STDERR_FILENO, str, strlen(str));
	write(STDERR_FILENO, ": unknown instruction ", 22);
	write(STDERR_FILENO, instruction, strlen(instruction));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
/**
  * inst - deciphers intstructions in a file
  *
  * @stack: stack provided
  *
  * @token: token received from a file
  *
  * @f: file to close in case of an error
  *
  * @counter: counter for lines to count lines in the file
  *
  */

void inst(stack_t **stack, char *token, unsigned int counter, FILE *f)
{
	void (*redirecting)(stack_t **stack, unsigned int line_number);
	int y, value = 0, valid_instruction = 0;
	char lowered[BUFSIZ], *delim = " \n";

	while (token != NULL)
	{
		strcpy(lowered, token);
		for (y = 0; lowered[y] != '\0'; y++)
			lowered[y] = tolower(lowered[y]);
		if (strcmp(lowered, "push") == 0)
		{
			token = strtok(NULL, delim);
			value = check_push_value(token, f);
			if (value == 1)
			{
				push_value = atoi(token), redirecting = redirect("push");
				redirecting(stack, counter), token = strtok(NULL, delim);
				valid_instruction = 1;
				continue;
			} else
			{
				push_value = -1, redirecting = redirect("push");
				redirecting(stack, counter);
			}
		} else if (_cmp(lowered))
		{
			if (strcmp(lowered, "add") == 0 || strcmp(lowered, "sub") == 0 ||
					strcmp(lowered, "dv") == 0)
				check_addError(f, stack, counter, lowered);
			if (strcmp(lowered, "pop") == 0)
				pop_error(*stack, f, counter);
			redirecting = redirect(lowered), redirecting(stack, counter);
			token = strtok(NULL, delim), valid_instruction = 1;
			continue;
		}
		token = strtok(NULL, delim);
		if (token == NULL && valid_instruction == 0)
			error_instruction(lowered, counter);
	}
}
/**
  * file_error - prints error
  *
  * @file_name: file name provided
  */
void file_error(char *file_name)
{

	write(STDERR_FILENO, "Error: Can't open file ", 23);
	write(STDERR_FILENO, file_name, strlen(file_name));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

/**
  * read_file - read file provided
  *
  * @file_name: file name passed
  *
  */
void read_file(char *file_name)
{
	FILE *f;
	char buffer[BUFSIZ], *token, *delim = " \n";
	stack_t *stack = NULL;
	unsigned int counter = 0;

	f = fopen(file_name, "r");
	if (f == NULL)
		file_error(file_name);
	while (fgets(buffer, sizeof(buffer), f) != NULL)
	{
		counter++;
		token = strtok(buffer, delim);
		inst(&stack, token, counter, f);
	}
	free_stack(stack);
	fclose(f);
}
