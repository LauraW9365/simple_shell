#include "shell.h"
#include <stddef.h>

/**
* _strcon - concatenates two strings
* @dest: destination string
* @src: source string
* @n:no. of characters to concatenate
* Return: concatenated string
*/

char *_strcon(char *dest, char *src, int n)
{
	int     m = 0;
	int     p = 0;

	while (dest[m] != '\0')
		m++;

	while (src[p] != '\0' && p < n)
	{
		dest[m] = src[p];
		m++;
		p++;
	}

	dest[m] = '\0';

	return (dest);
}

/**
* _strncpy - copy the string pointed by src to dest
* @src: string to be copied
* @dest: destination string
* @n: numbe rof char
* Return: A pointer to the destination string
*/

char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

