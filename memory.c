#include "shell.h"

/**
 * free_arr - Free memory allocated for an array of strings.
 *
 * @arr: An array of strings to be freed.
 *
 * Return: No return value.
 */

void free_arr(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
