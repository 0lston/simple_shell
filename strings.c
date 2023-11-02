#include "shell.h"

/**
 * _strdup - Returns a pointer to a newly-allocated space in memory
 *           containing a copy of the string given as parameter.
 * @str: The string to be copied.
 *
 * Return: NULL - If str == NULL or insufficient memory is available.
 *         Otherwise - a pointer to the duplicated string.
 */

char *_strdup(char *str)
{
	char *dup;
	int i = 0;

	if (!str)
		return (NULL);
	while (str[i])
		i++;

	dup = (char *)malloc(i + 1);

	if (!dup)
		return (NULL);
	for (i = 0; str[i]; i++)
		dup[i] = str[i];

	dup[i] = '\0';

	return (dup);
}

/**
 * _strcmp - compares two strings.
 * @s1: A pointer to the first string to be compared.
 * @s2: A pointer to the second string to be compared.
 *
 * Return: a value indicating the relationship between the two strings:
 *		Less than 0	: string1 less than string2.
 *		0		: string1 identical to string2.
 *		Greater than 0	: string1 greater than string2.
 *
 */


int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s2[i] && s1[i])
		i++;

	return (s1[i] - s2[i]);
}

/**
 * _strcpy - Copies a string pointed to by @src, including the
 *           terminating null byte, to a buffer pointed to by @dest.
 * @dest: A buffer to copy the string to.
 * @src: The source string to copy.
 *
 * Return: A pointer to the destination string @dest.
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i); i++)
		*(dest + i) = *(src + i);
	*(dest + i) = '\0';
	return (dest);
}

/**
 * _strlen - Returns the length of a string.
 * @s: The string to get the length of.
 *
 * Return: The length of @s.
 */

int _strlen(char *s)
{
	int n = 0;

	while (*s++)
		n++;
	return (n);
}

/**
 * _strcat -	Concatenates the string pointed to by @src,
 *	    including the terminating null byte, to the end
 *	    of the string pointed to by @dest.
 *
 * @dest: A pointer to the string to be concatenated upon.
 * @src: The source string to be appended to @dest.
 *
 * Return: A pointer to the destination string @dest.
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';

	return (dest);
}
