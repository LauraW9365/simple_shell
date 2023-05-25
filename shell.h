#ifndef SHELL_H
#define SHELL_H


/*
 * ---LIBRARIES---
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 1024


/*
 * ---PROTOTYPES---
 */
void shell_interactive(void);
void shell_no_interactive(void);


/*---Macros---*/
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/*---PROTOTYPES---*/
void shell_interactive(void);
void shell_no_interactive(void);
char **split_line(char *line, const char *delimiter);
int execute_command(const char *command, char **args);
ssize_t my_setenv(const char *name, const char *value, int overwrite);
ssize_t my_unsetenv(const char *name);
int _strcompr(const char *str1, const char *str2);
void _rstr(char *str);
int _strlen(char *str);
char *_strcon(char *dest, char *src, int n);
char *_strncpy(char *dest, const char *src, size_t n);
void _freeloop(char **array);
char **_tokenize(char *line);
char *_gettenv(const char *type, char **env);
ssize_t _getline(char **lineptr, size_t *n, FILE *str);
char *_realloc(char *ptr, size_t size1, size_t new_size);



#endif
