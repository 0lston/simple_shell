#include "shell.h"

/**
 * read_input - Read a line of input from the user.
 *
 * This function reads a line of input from the user and returns it as a
 * dynamically allocated string.
 *
 * Return: A pointer to the input, or NULL on failure.
 */

char *read_input(void)

{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}

/**
 * parser - Parse a string into an array of command arguments.
 *
 * @line: The input string to be parsed.
 *
 * Return: An array of strings representing the parsed command arguments,
 *	   or NULL on failure.
 */

char **parser(char *line)
{
	char **commands;
	char *args;
	int i = 0;
	char *tmp = _strdup(line);

	args = strtok(tmp, DELLIM);
	if (!args)
	{
		free(tmp);
		free(line);
		return (NULL);
	}
	while (args)
	{
		args = strtok(NULL, DELLIM);
		i++;
	}
	free(tmp);

	commands = malloc(sizeof(char *) * (i + 1));
	if (!commands)
	{
		free(line);
		return (NULL);
	}


	args = strtok(line, DELLIM);

	for (i = 0; args; i++)
	{
		commands[i] = _strdup(args);
		args = strtok(NULL, DELLIM);
	}

	commands[i] = NULL;
	free(line);
	return (commands);
}
