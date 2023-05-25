#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt() {
    printf("shell> ");
    fflush(stdout);
}

void execute_command(char *command) {
    if (strcmp(command, "exit") == 0) {
        exit(0);
    } else {
        // Execute the command using system() or execvp() or any other desired method
        // Here, we'll just print the command for demonstration purposes
        printf("Executing command: %s\n", command);
    }
}

int main(void) {
    int is_interactive = isatty(STDIN_FILENO);

    if (is_interactive) {
        char command[MAX_COMMAND_LENGTH];

        while (1) {
            display_prompt();

            if (fgets(command, sizeof(command), stdin) == NULL) {
                // Handle end of file (Ctrl+D)
                printf("\n");
                exit(0);
            }

            // Remove the trailing newline character
            command[strcspn(command, "\n")] = '\0';

            if (strlen(command) > 0) {
                execute_command(command);
            }
        }
    } else {
        // Run the shell in non-interactive mode
        printf("Non-interactive mode not supported.\n");
    }

    return 0;
}

