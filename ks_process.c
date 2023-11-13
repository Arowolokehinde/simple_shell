#include "shell.h"

/**
 * fork_shell - function that creates the child process of the shell
 * @cmd: command path parameter passed for execution
 * @argument: command argument passed for execution
 * @cmd_in: This argument vector
 * Written by Sunday and Kehinde
 * Return: Always sucess
 */

int fork_shell(char *cmd, char **argument, char *cmd_in)
{
	int status, stat;
	pid_t sunday_pid = fork();

	if (sunday_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (sunday_pid == 0)
	{
		if (strspn(cmd, DELIMS) == strlen(cmd))
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		if (execve(cmd, argument, environ) == -1)
		{
			perror(cmd_in);
			free(argument);
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(sunday_pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status))
			stat = WEXITSTATUS(status);
	}
	return (stat);
}
