#include "shell.h"

/**
* _gettenv - gets the environmebt variable
* @env: environ
* @type: name of the environment variable
* Return: variable
*/

char *_gettenv(const char *type, char **env)
{
	char *cos = NULL;
	int m = 0;

	if (env == NULL)
		return (NULL);

	while (env[m] != NULL)
	{
		cos = strtok(env[m], "=");
		if (_strcompr(cos, type) == 0)
		{
			return (strtok(NULL, "\n"));
		}
		m++;
	}

	return (NULL);
}
