#include "shell.h"

/**
 * get_environment - Function that gets the name of  a path from environment
 * @environment_name: This is the name of the path in the environment
 *
 * Return: Always success
 */

char *get_environment(const char *environment_name)
{
	int amount;
	int length = 0;
	char *environment;

	for (amount = 0; environ[amount]; amount++)
	{
		environment = environ[amount];
		length = strlen(environment_name);

		if (strncmp(environment, environment_name, length) == 0
				&& environment[length] == '=')
		{
			return (&environment[length + 1]);
		}
	}
	return (NULL);
}
