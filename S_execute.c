#include "shell.h"

/**
 * execute_prompt - Function that process and executes the command input
 * @parameter: This is a pointer to the struct
 * Description: This function would create a fork process for
 * the user input command and execute it
 * Return: Always success
 */

int execute_prompt(basicshell *parameter)
{
	int status = 0  /*status,*/;
	char **com_execute = argument_Tok(parameter->cmd_in);
	char cmdPath[HIGHEST_BUFFER];

	if (com_execute == NULL)
	{
		free_argument(com_execute);
		free(parameter->cmd_in);
		return (0);
	}
	if (strcmp(com_execute[0], "exit") == 0)
	{
		free_argument(com_execute);
		free(parameter->cmd_in);
		exit_shell();
	}
	else if (strcmp(com_execute[0], "env") == 0)
		environment();
	else
	{
		if (cmd_topath(com_execute[0], cmdPath))
		{
			status = fork_shell(cmdPath, com_execute, parameter->avec[0]);
		}
		else
		{
			status = fork_shell(com_execute[0], com_execute, parameter->avec[0]);
		}
		if (status == -1)
		{
			execute_err(com_execute[0], parameter->avec[0], parameter->res_counts);
		}
	}
	free_argument(com_execute);
	return (status);
}
