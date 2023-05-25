#include "shell.h"
#include <string.h>

/**
* _freeloop - free array of pointers
* @array: array of pointers
*/

void _freeloop(char **array)
{
	int j = 0;

	while (array[j] != NULL)
	{
		free(array[j]);
		j++;
	}
	free(array);
}

/**
* _tokenize - split string into tokens
* @line: input string to be split into lines
* Return: array containing tokens
*/
char **_tokenize(char *line)
{
	int z = 0;
	char *token;
	char *hash;

	char **spell;
	int m;

	m = _strlen(line);
	spell = malloc(sizeof(char *) * (m + 1));

	if (spell == NULL)
		return (NULL);
	hash = strtok(line, "#");
	token = strtok(hash, TOK_DELIM);

	for (; token != NULL; token = strtok(NULL, TOK_DELIM), z++)
	{
		spell[z] = malloc(_strlen(token) + 1);
		if (spell[z] == NULL)
		{
			_freeloop(spell);
			return (NULL);
		}
		_strncpy(spell[z], token, _strlen(token) + 1);
	}

	spell[z] = NULL;
	return (spell);
}


