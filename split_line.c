#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50

/**
 * split_line - Tokenize a string based on a delimiter
 * @line: Input string to be tokenized
 * @delimiter: Delimiter used to split the string
 *
 * Return: Array of pointers to the individual tokens
 */
char **split_line(char *line, const char *delimiter)
{
    int token_count = 0;
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    char *token;

    if (tokens == NULL)
    {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, delimiter);
    while (token != NULL)
    {
        tokens[token_count] = strdup(token);
        token = strtok(NULL, delimiter);
        token_count++;

        if (token_count >= MAX_TOKENS)
        {
            /* Increase the size of tokens array if needed */
            char **new_tokens = realloc(tokens, (MAX_TOKENS * 2) * sizeof(char *));
            if (new_tokens == NULL)
            {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
            tokens = new_tokens;
            MAX_TOKENS *= 2;
        }
    }
    tokens[token_count] = NULL;

    return tokens;
}

int main(void)
{
    char input[] = "This is a sample input string";
    char **tokens;

    tokens = split_line(input, " ");
    if (tokens != NULL)
    {
        int i = 0;
        while (tokens[i] != NULL)
        {
            printf("Token %d: %s\n", i, tokens[i]);
            free(tokens[i]);
            i++;
        }
        free(tokens);
    }

    return 0;
}

