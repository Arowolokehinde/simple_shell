#include "shell.h"

/**
 * main - This is the entry point to the shell code
 * @ac: argument count
 * @avec: The argument string(vector)
 * Return: Always success
 */

int main(int ac, char *avec[])
{
	basicshell parameter;
	(void)ac;

	parameter = init_basicshell(avec);

	show_prompt(&parameter);
	free(parameter.cmd_in);
	return (0);
}
