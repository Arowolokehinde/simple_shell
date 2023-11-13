#include "shell.h"

/**
 * resize_buffer - A function that reallocates memory if the buffer is full
 * @line: pointer to the input
 * @len: size of the input
 * @nsize: required size to be reallocated
 * Return:Always success
 */

void resize_buffer(char **line, size_t *len, size_t nsize)
{
	char *str;
	size_t changeSize = (*len) * 2, p;

	while (changeSize <= nsize)
		changeSize *= 2;
	str = (char *)malloc(changeSize);

	if (str == NULL)
		return;

	for (p = 0; p < nsize; p++)
		str[p] = (*line)[p];
	free(*line);
	*line = str;
	*len = nsize;
}
