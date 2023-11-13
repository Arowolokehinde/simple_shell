#include "shell.h"

/**
 * **argument_Tok - function takes command parses and tokenize it
 * @cmd: string command agruments to be tokenized
 * Return: Always success
 */

char **argument_Tok(char *cmd)
{
	int i, argument_num = 0;
	char *token_process = strtok(cmd, " ");

	char **str = (char **)malloc(sizeof(char *) * (HIGHEST_CMD_ARG + 1));

	if (str == NULL)
	{
		perror("FAILED");
		exit(EXIT_FAILURE);
	}

	while (token_process != NULL && argument_num < HIGHEST_CMD_ARG)
	{
		str[argument_num] = strdup(token_process);
		if (str[argument_num] == NULL)
		{
			perror("Failure of strdup");
			for (i = 0; i < argument_num; i++)
				free(str[i]);
			free(str);
			exit(EXIT_FAILURE);
		}
		token_process = strtok(NULL, " ");
		argument_num++;
	}
	str[argument_num] = NULL;
	return (str);
}
/**
 * free_argument - function frees the memory assigned to execom array
 * from the tokenized process
 * @str: pointer to the array of string
 * Return: returns void
 */

void free_argument(char **str)
{
	int k;

	for (k = 0; str[k] != NULL; k++)
		free(str[k]);
	free(str);
}
