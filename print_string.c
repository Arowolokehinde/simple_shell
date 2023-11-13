#include "shell.h"

/**
 * print_string - A Function prints string to the standard output
 * @input: The string to be printed
 * Return: always success
 */
void print_string(const char *input)
{
	write(STDOUT_FILENO, input, strlen(input));
}

/**
 * showthis - Function displays the name of the shell
 * Return: returns void.
 */
void showthis(void)
{
	char *input = "Cisfun $: ";

	print_string(input);
	fflush(stdout);
}
