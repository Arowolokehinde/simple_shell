#include "shell.h"

/**
 * ksget_line - function gets input from the user
 * @line: pointer to the input command given by the user
 * @len: size of the input
 * @stream: where to read the input from
 * Return: Always success
 */
ssize_t ksget_line(char **line, size_t *len, FILE *stream)
{
	static char str_in[HIGHEST_CMD_ARG];
	static size_t str_index;
	static size_t str_size ; /** str is buffer */
	size_t i = 0;
	char p;

	if (line == NULL || len == NULL)
		return (-1);
	if (*line == NULL || len == 0)
	{
		free(*line);
		*line = (char *)malloc(HIGHEST_CMD_ARG);
		if (*line == NULL)
			return (-1);
		*len = HIGHEST_CMD_ARG;
	}
	while (1)
	{
		if (str_index >= str_size)
		{
			str_size = read(fileno(stream), str_in, HIGHEST_CMD_ARG);
			if (str_size <= 0)
			{
				if (i == 0)
					return (-1);
			} else
			{
				(*line)[i] = '\0'; /*Null terminating string*/
				return (i);
			}
		} str_index = 0;
		p = str_in[str_index++];
		(*line)[i++] = p;
		if (p == '\n')
		{
			(*line)[i++] = '\0';
			return (i);
		}
		if (i >= *len - 1)
			resize_buffer(line, len, i + 1);
	}
}
