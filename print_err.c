#include "shell.h"

/**
 * _atoi - Convert an integer to a string.
 * @num: The integer to be converted.
 *
 * Return: The string representing the integer.
 */

char *_atoi(int num)
{
	char digits[] = "0123456789";
	char buffer[50];
	char *ptr = &buffer[49];
	char* output;
	*ptr = '\0';
	do {
		*--ptr = digits[num % 10];
		num /= 10;
	} while (num);
    output=_strdup(ptr);
	return (output);
}

/**
 * print_err - Print error messages.
 * @name: The name of the program.
 * @command: The command.
 * @counter: The counter value.
 *
 * This function prints an error message to the standard error stream.
 */

void print_err(char *name, char *command, int counter)
{
	/*counter to ascii*/
	char *a_counter = _atoi(counter);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, a_counter, _strlen(a_counter));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);

	free(a_counter);
}
