#include "shell.h"

/**
 * execute_err - function that checks for error in the command
 * @cmd_in: command line argument
 * @amounts: gives the error line count
 * @cmd: command input
 * Return: Always success
 */

int execute_err(char *cmd, char *cmd_in, int amounts)
{
	int length;
	char *counts = conItoA(amounts);
	char *err_msg;

	length = strlen(cmd_in) + strlen(counts);
	length = length + strlen(cmd) + 16;
	err_msg = malloc(sizeof(char) * (length + 1));

	if (err_msg == NULL)
	{
		free(counts);
		return (-1);
	}

	strcpy(err_msg, cmd_in);
	strcat(err_msg, ": ");
	strcat(err_msg, counts);
	strcat(err_msg, ": ");
	strcat(err_msg, cmd);
	strcat(err_msg, ": not found\n");
	strcat(err_msg, "\0");

	write(STDOUT_FILENO, err_msg, strlen(err_msg));
	free(counts);
	free(err_msg);
	return (127);
}
