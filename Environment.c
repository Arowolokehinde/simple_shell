#include "shell.h"

/**
 * environment - function that prints the environment to the standard output
 * Description: this function is the implementation of the environment
 * function that prints all the environments in a system
 * Return: Always success
 */
void environment(void)
{
	char **env = environ;

	while (*env)
	{
		if (write(STDOUT_FILENO, *env, strlen(*env)) == -1)
		{
			perror("WRITE");
			exit(EXIT_FAILURE);
		}
		if (write(STDOUT_FILENO, "\n", 1) == -1)
		{
			perror("WRITE");
			exit(EXIT_FAILURE);
		}
		env++;
        }
}
