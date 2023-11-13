#include "shell.h"

/**
 * cmd_topath -  function that checks if the input commaind is in path
 * @cmd: input command
 * @cmdPath: This is a buffer to hold tokenized path
 * Return: Always success
 */

int cmd_topath(char *cmd, char *cmdPath)
{
	char *str_path = get_environment("PATH");
	char *str_pathCpy;
	/* This is the memory allocated to store the path */
	char *str_pathTok;
	char *last = strrchr(cmd, '/');

	if (str_path == NULL || str_path[0] == '\0')
	{
		return (0);
	}
	if (last)
		cmd = (last + 1);
	str_pathCpy = malloc(strlen(str_path) + strlen(cmd) + 2);
	if (str_pathCpy == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	strcpy(str_pathCpy, str_path);
	str_pathTok = strtok(str_pathCpy, ": ");
	while (str_pathTok)
	{
		strcpy(cmdPath, str_pathTok);
		strcat(cmdPath, "/");
		strcat(cmdPath, cmd);
		if (execute_start(cmdPath))
		{
			free(str_pathCpy);
			return (1);
		}
		if (to_path(cmdPath))
		{
			free(str_pathCpy);
			return (1);
		}
		str_pathTok = strtok(NULL, ": ");
	}
	free(str_pathCpy);
	return (0);
}
