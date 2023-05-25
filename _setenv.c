#include "shell.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/**
 * my_setenv - set an environemnt variable
 * @name: string
 * @value: string
 * @overwrite: integer flag
 * Return: 0 or -1
*/

ssize_t my_setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || value == NULL)
	{
		write(STDERR_FILENO, "usage: my_setenv VARIABLE VALUE\n", 32);
		return (-1);
	}

	if (setenv(name, value, overwrite) == -1)
	{
		write(STDERR_FILENO, "Failed to set environment variable\n", 35);
		return (-1);
	}

	return (0);
}

/**
 * my_unsetenv - remove an environment variable
 * @name: string that is environment variable
 * Return: -1 or 0
*/

ssize_t my_unsetenv(const char *name)
{
	if (name == NULL)
	{
		write(STDERR_FILENO, "usage: my_unsetenv VARIABLE\n", 28);
		return (-1);
	}

	if (unsetenv(name) == -1)
	{
		write(STDERR_FILENO, "Failed to unset environment variable\n", 37);
		return (-1);
	}

	return (0);
}
