#include "shell.h"

#define MAX_ALIASES 100

typedef struct {
    char name[50];
    char value[50];
} Alias;

Alias aliases[MAX_ALIASES];
int alias_count = 0;

// Function to print all aliases
void print_aliases() {
    for (int i = 0; i < alias_count; i++) {
        printf("%s='%s'\n", aliases[i].name, aliases[i].value);
    }
}

// Function to print the value of a specific alias
void print_alias_value(const char* name) {
    for (int i = 0; i < alias_count; i++) {
        if (strcmp(name, aliases[i].name) == 0) {
            printf("%s='%s'\n", aliases[i].name, aliases[i].value);
            return;
        }
    }
    printf("Alias '%s' not found.\n", name);
}

// Function to define or update an alias
void define_alias(const char* name, const char* value) {
    for (int i = 0; i < alias_count; i++) {
        if (strcmp(name, aliases[i].name) == 0) {
            strcpy(aliases[i].value, value);
            return;
        }
    }

    if (alias_count >= MAX_ALIASES) {
        printf("Maximum number of aliases reached.\n");
        return;
    }

    Alias new_alias;
    strcpy(new_alias.name, name);
    strcpy(new_alias.value, value);
    aliases[alias_count++] = new_alias;
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        // No arguments provided, print all aliases
        print_aliases();
    } else if (argc == 2) {
        // Single argument provided, print the value of the alias
        print_alias_value(argv[1]);
    } else {
        // Multiple arguments provided, define or update aliases
        for (int i = 1; i < argc; i++) {
            char* arg = argv[i];
            char* equals_sign = strchr(arg, '=');
            if (equals_sign != NULL) {
                // Argument contains '=', define or update alias
                *equals_sign = '\0';
                char* name = arg;
                char* value = equals_sign + 1;
                define_alias(name, value);
            } else {
                // Argument does not contain '=', print the value of the alias
                print_alias_value(arg);
            }
        }
    }

    // Demo of 'ls -l' functionality
    char* ls_args[] = {"ls", "-l", NULL};
    execvp("ls", ls_args);

    return 0;
}

