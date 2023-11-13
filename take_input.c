#include "shell.h"

/**
 * take_input - function handles the input given by the user
 * Description: this function when called, handle
 * the input of the user, using the getLine function
 * written by sunday and kehinde
 * @parameter: pointer to the struct where the string input given
 * @len: length of the string input given
 * Return: Always success
 */
void take_input(basicshell *parameter, size_t *len)
{
	ssize_t readIn = ksget_line(&(parameter->cmd_in), len, stdin);
	char *trim_cmd = parameter->cmd_in;

	if (readIn == -1)
	{
		if (feof(stdin))
		{
			free(parameter->cmd_in);
			parameter->cmd_in = NULL;
			exit(EXIT_SUCCESS);
		}
		exit(EXIT_FAILURE);
	}
	while ((*trim_cmd != '\0') && (*trim_cmd == ' ' || *trim_cmd == '\t'))
		trim_cmd++;
	if ((*trim_cmd == '\0'))
	{
		free(parameter->cmd_in);
		parameter->cmd_in = NULL;
		return;
	}
	if ((parameter->cmd_in)[readIn - 1] == '\n')
		(parameter->cmd_in)[readIn - 1] = '\0';
	if (*trim_cmd != '\0')
	{
		execute_prompt(parameter);
	}
	free(parameter->cmd_in);
	parameter->cmd_in = NULL;
}
