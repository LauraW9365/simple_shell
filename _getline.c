#include "shell.h"

/**
 * _getline - reads input
 * @lineptr: buffer
 * @n: size of lineptr
 * @str: stream to read from
 * Return: no. of characters
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *str)
{
	static ssize_t input_count;
	ssize_t p;
	char j;
	size_t buffer_size = 130;
	char *buffer;

	if (input_count == 0)
	{
		setvbuf(str, NULL, _IONBF, 0);
		fclose(str);
	} else
	{
		return (-1);
	}
	input_count = 0;
	buffer = malloc(sizeof(char) * buffer_size);
	if (!buffer)
	{
		return (-1);
	}
	while ((j = getc(stdin)) != '\n')
	{
		if (j == EOF || (j == '\0' && input_count == 0))
		{
			free(buffer);
			return (-1);
		}
		if (j == '\0' && input_count != 0)
		{
			input_count++;
			break;
		}
		if ((size_t)input_count >= buffer_size)
		{
			buffer_size *= 2;
			buffer = _realloc(buffer, sizeof(char) * buffer_size, sizeof(char) * buffer_size);
			if (!buffer)
			{
				free(buffer);
				return (-1);
			}
		}
		buffer[input_count] = j;
		input_count++;
	}
	buffer[input_count] = '\0';
	assign_linepointer(lineptr, n, buffer, input_count);
	p = input_count;
	if (j != '\0')
	{
		input_count = 0;
	}
	return (p);
}
