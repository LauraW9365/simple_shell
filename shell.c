#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: 0 on success
 */
int main(void)
{
	int is_interactive = isatty(STDIN_FILENO);

	if (is_interactive)
	{
	/* Run the shell in interactive mode */
	shell_interactive();
	}
	else
	{
	/* Run the shell in non-interactive mode */
	shell_no_interactive();
	}

	return (0);
}
