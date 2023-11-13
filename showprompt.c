#include "shell.h"

/**
 * show_prompt - shows the propmtof the shell in an infinite loop
 * Description: This function calls necessary functions and run them in
 * @parameter: points to the struct with defined members
 * This is the user input command e.t.c
 * This prompt display function, executing and handling
 * Return: Always success
 */

void show_prompt(basicshell *parameter)
{
	int display = 1;
	size_t len = 0; /* this is the length of the input given */

	while (1)
	{
		if (isatty(STDIN_FILENO))
			showthis();
		else if (parameter->cmd_in == NULL || strlen(parameter->cmd_in) == 0)
		{
			free(parameter->cmd_in);
			parameter->cmd_in = NULL;
		}

		else
		{
			if (!display)
				showthis();
		}
		take_input(parameter, &len);
	}
}
