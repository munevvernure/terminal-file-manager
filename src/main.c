#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/file_operations.h"
#include "../include/directory_ops.h"
#include "../include/permissions.h"
#include "../include/logger.h"

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
                printf("  dlist <path>                    - List directory contents\n");
                printf("  dcreate <path>                  - Create directory\n");
                printf("  dremove <path>                  - Delete directory\n");
                printf("  fread <path>                    - Read file contents\n");
                printf("  fwrite <path> <content>         - Writes to the file\n");
                printf("  fcopy <src> <dest>              - Copy file\n");
                printf("  fremove <path>                  - Delete file\n");
                printf("  fmove <src> <dest>              - Moves file to the destination\n");
                printf("  pcheck <path>                   - Check permissions of a file or directory\n");
                printf("  pchange <path> <permissions>    - Change permissions (permissions in octal format, e.g., 0644)\n");
                printf("  logwrite <log_file> <message>   - Write a log entry with the specified message\n");
                printf("  logread <log_file>              - Read and display the contents of the specified log file\n");

            } else if (strcmp(arg1, "fwrite") == 0) {
                if (strlen(arg2) > 0 && strlen(content) > 0) {
                    write_file(arg2, content); // arg2: path, content: content to be written
                } else {
                    printf("Invalid command format for swrite. Use: swrite <path> <content>\n");
                }

            } else if (strcmp(arg1, "dlist") == 0) {
                  list_directory(arg2);

            } else if (strcmp(arg1, "dcreate") == 0) {
                  create_directory(arg2);
                  
            } else if (strcmp(arg1, "dremove") == 0) {
                  delete_directory(arg2);
            
            } else if (strcmp(arg1, "fread") == 0) {
                read_file(arg2);

            } else if (strcmp(arg1, "fremove") == 0) {
                delete_file(arg2);

            } else if (strcmp(arg1, "fcopy") == 0) {
                sscanf(command, "%*s %127s %[^\n]", arg2, content);
                copy_file(arg2, content);
                printf("File content is successfully copied from %s to %s\n", arg2, content);

            } else if (strcmp(arg1, "fmove") == 0 ) {
                sscanf(command, "%*s %127s %[^\n]", arg2, content);
                move_file(arg2, content);
            
            } else if (strcmp(arg1,"pcheck") == 0) {
                check_permissions(arg2);
            
            } else if (strcmp(arg1, "pchange") == 0) {
                if (strlen(command) > 0) {
                int permissions = strtol(command, NULL, 8);
                change_permissions(arg2, permissions);
            } else {
                printf("Error: Please specify the permissions in octal format.\n");
            }
          } else if (strcmp(arg1, "logwrite") == 0) {
                sscanf(command, "%*s %127s %[^\n]", arg2, content);
                write_log(arg2, content);
          } else if (strcmp(arg1, "logread") == 0) {
                read_logs(arg2);
          
          } else {
                printf("Invalid command or arguments. Type 'help' for assistance.\n");
            }

        } else {
            printf("Invalid command format. Type 'help' for assistance.\n");
        }
    }

    return 0;
}

