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
typedef struct kennyshell
{
	char *cmd_in;/* User command input*/
	char **avec;/*main argument vector*/
	char **cmds;/*commands*/
	char *path; /*path of the environment*/
	int out_status;/*output status*/
	int res_counts;/*result counts*/
} basicshell;

basicshell init_basicshell(char **avec);
void show_prompt(basicshell *parameter);
int execute_prompt(basicshell *parameter);
void take_input(basicshell *parameter, size_t *len);
char **argument_Tok(char *cmd);
void free_argument(char **str);

int fork_shell(char *cmd, char **argument, char *cmd_in);
void print_string(const char *input);
void showthis(void);


int numberlen(int number);
char *conItoA(int number);


ssize_t ksget_line(char **line, size_t *len, FILE *stream);
void resize_buffer(char **line, size_t *len, size_t nsize);

int cmd_topath(char *cmd, char *cmdPath);
int execute_start(const char *pathbuffer);
void exit_shell(void);
void environment(void);
char *get_environment(const char *env_name);
int to_path(const char *Pathbuffer);

int execute_err(char *cmd, char *cmd_in, int amounts);


#endif
