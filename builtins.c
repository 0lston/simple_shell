#include "shell.h"

/**
 * is_builtin - Check if a command is a builtin.
 * @command: The command to check.
 *
 * Return: 1 if the command is a builtin, 0 otherwise.
 */
int is_builtin(char *command)
{
	char *builtins[] = {
		"env", "exit", NULL
	};
	int i = 0;

	for (i = 0; builtins[i]; i++)
	{
		if (!_strcmp(builtins[i], command))
			return (1);
	}
	return (0);
}

/**
 * builtin_handler - Handle builtin commands.
 * @commands: The list of commands.
 * @av: The argument vector.
 * @status: The status.
 * @counter: The counter value.
 */

void builtin_handler(char **commands, char **av, int *status, int counter)
{
	(void)counter;
	(void)av;
	if (!_strcmp(commands[0], "exit"))
		exit_shell(commands, status);
	else if (!_strcmp(commands[0], "env"))
		print_env(commands, status);
}

/**
 * exit_shell - Exit the shell.
 * @commands: The list of commands.
 * @status: The status.
 */

void exit_shell(char **commands, int *status)
{
	free_arr(commands);
	exit(*status);
}

/**
 * print_env - Print the environment.
 * @commands: The list of commands.
 * @status: The status.
 */

void print_env(char **commands, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_arr(commands);
	*status = 0;
}