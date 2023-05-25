#include "shell.h"

/**
* _strcompr - performs comparison of 2 strings
* @str1: first string
* @str2: second string
* Return: difference from comparison
*/

int _strcompr(const char *str1, const char *str2)
{
	if (str1 == NULL && str2 == NULL)
		return (0);
	else if (str1 == NULL || str2 == NULL)
		return (1);

	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);

		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
* _rstr - reverses a string
* @str: pointer to string to be reversed
* Return: void
*/

void _rstr(char *str)
{
	int m = 0;
	int j = 0, c;
	char pr;

	while (str[m] != '\0')
	{
		m++;
	}

	c = m - 1;

	for (; c >= 0 && j < c; c--, j++)
	{
		pr = str[j];
		str[j] = str[c];
		str[c] = pr;
	}
}

/**
* _strlen - gets the length of a string
* @str: the pointer to the string
* Return: length of the string
*/

int _strlen(char *str)
{
	int m = 0;

	for (; str[m] != '\0'; m++)
	{

	}
	return (m);

}

