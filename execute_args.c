#include "shell.h"

/**
 * execute_exit - Execute the 'exit' built-in command
 * @args: Array of command arguments
 *
 * Return: The return value for the 'exit' command
 */
int execute_exit(char **args)
{
    /* Add any necessary cleanup before exiting */
    exit(0);
}

/**
 * execute_cd - Execute the 'cd' built-in command
 * @args: Array of command arguments
 *
 * Return: The return value for the 'cd' command
 */
int execute_cd(char **args)
{
    /* Add implementation for changing directory */
    /* Use args[1] as the target directory */
    /* Handle error cases appropriately */
    return 0;
}

/**
 * execute_builtin - Execute a built-in command
 * @command: Command to execute
 * @args: Array of command arguments
 *
 * Return: The return value for the built-in command
 */
int execute_builtin(const char *command, char **args)
{
    if (strcmp(command, "exit") == 0)
    {
        return execute_exit(args);
    }
    else if (strcmp(command, "cd") == 0)
    {
        return execute_cd(args);
    }
    /* Add more built-in commands here */

    return -1;  // Command not found
}

/**
 * execute_args - Execute the command arguments
 * @command: Command to execute
 * @args: Array of command arguments
 *
 * Return: The return value for the command
 */
int execute_args(const char *command, char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        /* Child process */
        if (execvp(args[0], args) == -1)
        {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        /* Forking error */
        perror("fork");
        return -1;
    }
    else
    {
        /* Parent process */
        do
        {
            /* Wait for child process to complete */
            if (waitpid(pid, &status, WUNTRACED) == -1)
            {
                perror("waitpid");
                return -1;
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return status;
}

int main(void)
{
    char *args[] = {"ls", "-l", NULL};
    const char *command = "ls";

    int return_val = execute_builtin(command, args);
    if (return_val == -1)
    {
        return_val = execute_args(command, args);
    }

    printf("Command return value: %d\n", return_val);

    return 0;
}

