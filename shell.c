#include "shell.h"


/**
 * main - Entry point of the simple shell program.
 *
 * @ac: The number of command-line arguments.
 * @av: An array of strings representing the command-line arguments.
 *
 * Return: The exit status of the program.
 */

int main(int ac, char **av)

{
	char *input = NULL;
	char **commands = NULL;
	int status = 0;
	int counter = 0;
	(void) ac;

	while (1)
	{
		input = read_input();
		if (!input)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		counter++;
		commands = parser(input);
		if (!commands)
			continue;

		if (is_builtin(commands[0]))
			builtin_handler(commands, av, &status, counter);
		else
			status = _execute(commands, av, counter);
	}
}
