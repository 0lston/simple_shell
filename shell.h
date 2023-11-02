#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define DELLIM " \n\t"
extern char **environ;

/*parser*/
char *read_input(void);
char **parser(char *line);

/*strings*/
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_atoi(int num);

/*mem*/
void free_arr(char **arr);

/*path*/
char *_getenv(char *var);
char *getpath(char *command);

/*builtins*/
int is_builtin(char *command);
void builtin_handler(char **commands, char **av, int *status, int counter);
void exit_shell(char **commands, int *status);
void print_env(char **commands, int *status);

/*execute*/
int _execute(char **commands, char **av, int counter);

/*print_err*/
void print_err(char *name, char *command, int counter);

#endif
