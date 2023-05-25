#include "shell.h"

/*Function to display help information*/
void help_command(const char* command) {
  if (command == NULL || strlen(command) == 0) {
    // Display general help information
    printf("Shell Help:\n");
    printf("  Available commands:\n");
    printf("    help - Display help information\n");
    printf("    cd   - Change the current directory\n");
    /*Add more commands and their descriptions here*/
  } else {
    /*Display help information for a specific command*/
    if (strcmp(command, "help") == 0) {
      printf("help - Display help information\n");
      printf("Usage: help [COMMAND]\n");
      printf("Description: Display general help information or help for a specific command.\n");
    } else if (strcmp(command, "cd") == 0) {
      printf("cd - Change the current directory\n");
      printf("Usage: cd [DIRECTORY]\n");
      printf("Description: Change the current directory to the specified DIRECTORY.\n");
      printf("If no argument is given, the command is interpreted as 'cd $HOME'.\n");
      printf("To change to the previous directory, use 'cd -'.\n");
    } else {
      printf("help: Unknown command '%s'.\n", command);
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc > 1) {
    /*Invoke the help_command function with the provided argument*/
    help_command(argv[1]);
  } else {
    /* Display general help information*/
    help_command(NULL);
  }

  return 0;
}

