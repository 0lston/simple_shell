#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @var: The name of the environment variable.
 *
 * This function retrieves the value of a specific environment variable.
 * It iterates through the array of environment variables until it finds
 * the desired variable, and then returns its value.
 *
 * Return: The value of the environment variable, or NULL if it doesn't exist.
 */

char *_getenv(char *var)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (!_strcmp(key, var))
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}

/**
 * getpath - Get the full path to a command.
 * @command: The command name.
 *
 * This function retrieves the full path to a command by searching through
 * the directories listed in the 'PATH' environment variable. It concatenates
 * the command name with each directory in the 'PATH' until it finds the
 * full path to the command.
 *
 * Return: The full path to the command, or NULL if it's not found.
 */

char *getpath(char *command)
{
	char *env, *dir;
	char *path_to_cmd;
	struct stat st;
	int i = 0;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (!stat(command, &st))
				return (_strdup(command));
			return (NULL);
		}
	}

	env = _getenv("PATH");
	if (!env)
		return (NULL);
	dir = strtok(env, ":");
	while (dir)
	{
		path_to_cmd = malloc(_strlen(command) + _strlen(dir) + 2);
		if (path_to_cmd)
		{
			_strcpy(path_to_cmd, dir);
			_strcat(path_to_cmd, "/");
			_strcat(path_to_cmd, command);

			if (!stat(path_to_cmd, &st))
			{
				free(env);
				return (path_to_cmd);
			}
			free(path_to_cmd);
		}
		dir = strtok(NULL, ":");
	}
	free(env);
	return (NULL);

}
