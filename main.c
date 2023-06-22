#include "monty.h"
/**
  * main - Entry point
  *
  * @argc: count arguments
  *
  * @argv: arguments
  * Return: succes 0
  */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	read_file(argv[1]);
	return (0);
}
