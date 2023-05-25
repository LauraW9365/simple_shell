#include "shell.h"

int main() {
    const char* new_directory = "/path/to/new_directory";

    if (chdir(new_directory) != 0) {
        perror("chdir");
        return 1;
    }

    // Print the updated working directory
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current directory: %s\n", cwd);
    } else {
        perror("getcwd");
        return 1;
    }

    return 0;
}

