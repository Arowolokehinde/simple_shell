#include "shell.h"

/**
 * execute_start - function that checks if the path is executable
 * @pathbuffer: pointer to the constructed path to be checked
 * Return: Always success
 */

int execute_start(const char *pathbuffer)
{
	struct stat filestart;

	if (stat(pathbuffer, &filestart) == 0)
	{
		if (S_ISREG(filestart.st_mode) && (filestart.st_mode & S_IXUSR))
			return (1);
	}
	return (0);
}
