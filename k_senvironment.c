#include "shell.h"

/**
 * get_environment - Function that gets the name of  a path from environment
 * @environment_name: This is the name of the path in the environment
 *
 * Return: Always success
 */

char *get_environment(const char *env_name)
{
	int len = 0;
	int i;
	char *_env;

	for (i = 0; environ[i]; i++)
	{
		_env = environ[i];
		len = strlen(env_name);
		if (strncmp(_env, env_name, len) == 0 && _env[len] == '=')
			return (&_env[len + 1]);
	}
	return (NULL);
}
