#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/file_operations.h"

//Function declarations
/*void list_directory(const char* path);
void copy_file(const char* srcvoid, const char* dest);
void delete_file(const char* path);
void change_permissions(const char* path, int permissions); */

int main(){
    char command[256];
    char arg1[128], arg2[128], content[256];

    printf("Terminal File Manager\n");
    printf("Type 'help' for the list of commands. Type 'exit' when you want to exit program\n");

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        // Parse the commands
        if (sscanf(command, "%s %127s %[^\n]", arg1, arg2, content) >= 1) {
            if (strcmp(arg1, "exit") == 0) {
                printf("Exiting program.\n");
                break;

            } else if (strcmp(arg1, "help") == 0) {
                printf("Available commands:\n");
                printf("  slist <path>        - List directory contents\n");
                printf("  sread <path>        - Read file contents\n");
                printf("  swrite <path> <content> - Writes to the file\n");
                printf("  scopy <src> <dest>  - Copy file\n");
                printf("  sremove <path>      - Delete file\n");
                printf("  chmod <path> <perm> - Change permissions\n");

            } else if (strcmp(arg1, "swrite") == 0) {
                if (strlen(arg2) > 0 && strlen(content) > 0) {
                    write_file(arg2, content); // arg2: path, content: content to be written
                } else {
                    printf("Invalid command format for swrite. Use: swrite <path> <content>\n");
                }

            } else if (strcmp(arg1, "slist") == 0) {
                // list_directory(arg2);

            } else if (strcmp(arg1, "sread") == 0) {
                read_file(arg2);

            } else if (strcmp(arg1, "sremove") == 0) {
                delete_file(arg2);

            } else if (strcmp(arg1, "scopy") == 0) {
                sscanf(command, "%*s %127s %[^\n]", arg2, content);
                copy_file(arg2, content);
                printf("File content is successfully copied from %s to %s\n", arg2, content);

            } else if (strcmp(arg1, "chmod") == 0) {
                int perm = strtol(content, NULL, 8);
                // change_permissions(arg2, perm);

            } else {
                printf("Invalid command or arguments. Type 'help' for assistance.\n");
            }

        } else {
            printf("Invalid command format. Type 'help' for assistance.\n");
        }
    }

    return 0;
}

