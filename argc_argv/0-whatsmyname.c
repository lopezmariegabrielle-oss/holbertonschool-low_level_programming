#include <stdio.h>

/**
 * main - Prints the name of the program, followed by a new line.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, __attribute__((unused)) char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);

	return (0);
}
