#include "shell.h"

int main(void)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)

	{
		/* Child process */
		if (execl("/bin/ls", "ls", "-l", NULL) == -1)
		{
			error("execl");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* Forking error */
		perror("fork");
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
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}

