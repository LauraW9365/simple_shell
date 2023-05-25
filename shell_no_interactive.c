#include "shell.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * shell_no_interactive - Unix command line interpreter for non-interactive mode
 *
 * This function reads commands from a script or input stream and executes them.
 * It continues reading and executing commands until an exit status is obtained.
 * Memory allocated for the line and arguments is freed to avoid leaks.
 *
 * Return: void
 */
void shell_no_interactive(void)
{
    char *line = NULL;
    size_t line_size = 0;
    ssize_t read;

    int status = -1;

    do {
        // Read a line of input from standard input
        read = getline(&line, &line_size, stdin);
        
        if (read == -1) {
            perror("getline");
            exit(1);
        }

        // Trim the newline character from the line
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }

        char **args = split_line(line); /* Tokenize line */
        
        
        // Free memory
        free(line);
        

        // Exit with status
        if (status >= 0)
            exit(status);

    } while (status == -1);
}

