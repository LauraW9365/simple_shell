#include "shell.h"

/*
 * shell_interactive - Run the shell in interactive mode
 */
void shell_interactive(void)
{
	char buffer[BUFFER_SIZE];
	char *command;

	while (1)
	{
	printf("$ ");  /* Prompt for input */
	fflush(stdout);

	/* Read input from the user */
	if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
	{
	break;  /* Exit the loop on error or end-of-file */
        }

        /* Remove the newline character from the end of the input */
	buffer[strcspn(buffer, "\n")] = '\0';

        /* Process and execute the command */
	command = strtok(buffer, " ");  /* Split the input into command and arguments */
	if (command != NULL)
	{
        /* Check if the command is "exit" */
        if (strcmp(command, "exit") == 0)
        {
        /* Get the status argument */
        char *status_str = strtok(NULL, " ");
        if (status_str != NULL)
        {
        /* Convert the status argument to an integer */
        int status = atoi(status_str);

        /* Free dynamically allocated memory */
	free(status_str);

	exit(status);
	}
	else
	{
	/* No status argument provided, exit with status 0 */
	exit(0);
	}
	}
        else
        {
        /* Execute the command (You need to implement the command execution logic) */
        /* ... */
            }
        }
    }
}

