#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


#define HIGHEST_CMD_ARG 128
#define HIGHEST_BUFFER 1024
#define DELIMS "  \t\n\a\r"

/*global variable*/
extern char **environ;

/**
 * struct bokangsh - structure takes all the neccessary information
 * of the shell
 * @cmd_in: User command input
 * @avec: main argument vector
 * @cmds: commands
 * @path: path of the environment
 * @res_counts: result counts
 * @out_status: output status
 */
typedef struct bokangsh
{
	char *cmd_in;/* User command input*/
	char **avec;/*main argument vector*/
	char **cmds;/*commands*/
	char *path; /*path of the environment*/
	int out_status;/*output status*/
	int res_counts;/*result counts*/
} basicshell;

basicshell init_basicshell(char **avec);
int numberlen(int number);
char *conItoA(int number);

char **argument_Tok(char *cmd);
void take_input(basicshell *parameter, size_t *len);
void environment(void);
int cmd_topath(char *cmd, char *cmdPath);
void free_argument(char **str);


ssize_t ksget_line(char **line, size_t *len, FILE *stream);
int execute_err(char *cmd, char *cmd_in, int amounts);
char *get_environment(const char *environment_name);
int execute_start(const char *pathbuffer);


void exit_shell(void);
int execute_prompt(basicshell *parameter);
void resize_buffer(char **line, size_t *len, size_t nsize);
void showthis(void);
void print_string(const char *input);
int to_path(const char *Pathbuffer);
void show_prompt(basicshell *parameter);
int fork_shell(char *cmd, char **argument, char *cmd_in);

#endif
