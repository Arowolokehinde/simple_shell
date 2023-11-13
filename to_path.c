#include "shell.h"

/**
 * to_path - This is a function that checks if path exist in environment
 * @Pathbuffer: this is the environment path to be checked
 * Return: Always success
 */
int to_path(const char *Pathbuffer)
{
	return ((access(Pathbuffer, F_OK) == 0));
}
