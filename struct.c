#include "shell.h"

/**
 * init_basicshell - Function initializes the struct
 * @avec: argument vector from the main function
 * Return: Always success
 */

basicshell init_basicshell(char **avec)
{
	basicshell memb;

	memb.cmd_in = NULL;
	memb.avec = avec;
	memb.out_status = 0;
	memb.cmds = NULL;
	memb.res_counts = 1;
	return (memb);
}
