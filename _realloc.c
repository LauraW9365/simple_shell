#include "shell.h"

/**
* _realloc - reallocating memory
* @ptr: a pointer
* @size1: size in bytes
* @new_size: size in bytes
* Return: pointer or NULL
*/

char *_realloc(char *ptr, size_t size1, size_t new_size)
{
	char *new_ptr;
	size_t copy_size;
	size_t i;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == size1 && ptr != NULL)
	{
		return (ptr);
	}
	new_ptr = malloc(sizeof(*new_ptr) * new_size);
	if (!new_ptr)
	{
		return (NULL);
	}
	copy_size = (size1 < new_size) ? size1 : new_size;
	for (i = 0; i < copy_size; i++)
	{
		new_ptr[i] = ptr[i];
	}
	free(ptr);
	return (new_ptr);
}

void assign_linepointer(char **line_ptr, size_t *line_size, char *buffer,
			ssize_t line_length)
{
	if (line_length <= 0)
	{
		*line_ptr = NULL;
		*line_size = 0;
	} else
	{
		char *temp_ptr = _realloc(*line_ptr, *line_size, line_length + 1);

		if (!temp_ptr)
		{
			return;
		}
		memcpy(temp_ptr, buffer, line_length);
		temp_ptr[line_length] = '\0';
		*line_ptr = temp_ptr;
		*line_size = line_length + 1;
	}
}
