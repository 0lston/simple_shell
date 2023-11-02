#include "shell.h"

/**
 * _execute - Execute a command and wait for it to finish.
 *
 * @commands: An array of strings representing the command and its arguments.
 * @av: An array of strings representing the program name and its arguments.
 * @counter: valid input counter
 *
 * Return: The exit status of the executed command.
 */

int _execute(char **commands, char **av, int counter)
{
	pid_t child;
	int status;
	char *command;

	command = getpath(commands[0]);

	if (!command)
	{
		print_err(av[0], commands[0], counter);
		free_arr(commands);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		execve(command, commands, environ);
	}
	else
	{
		waitpid(child, &status, 0);
		free_arr(commands);
		free(command);
	}
	return (WEXITSTATUS(status));
}
