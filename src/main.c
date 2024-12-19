#include <stdio.h>
#include <string.h>

//Function declarations
void list_directory(const char* path);
void copy_file(const char* src, const char* dest);
void delete_file(const char* path);
void change_permissions(const char* path, int permissions);

int main(){
char command[256];
char arg1[128], arg2[128];

printf("Terminal File Manager\n");
printf("Type 'help' for the list of commands.\n");

while(1){
  printf("> ");
  fgets(command,sizeof(command), stdin);
  command[strcspn(command, "\n")] = '\0';
  
  //Parse the commmands
  if(sscanf(command, "%s %s %s", arg1, arg2, command) == 1){
    if(strcmp(arg1, "exit") == 0){
      printf("Exiting program.\n");
      break;
      } else if(strcmp(arg1, "help") == 0){
        printf("Available commands:\n");
        printf("  slist <path>        -List directory contents\n");
        printf("  scopy <src> <dest>  -Copy file\n");
        printf("  sremove <path>      -Delete file\n");
        printf("  chmod <path> <perm> -Change permissions\n");
        }else {
        printf("Invalid command. Type 'help' for a list of commands.\n");
        }
        
      } else if(sscanf(command, "%s %s %s", arg1, arg2, command) == 2) {
          if (strcmp(arg1,"slist") == 0) {
              list_directory(arg2);
          } else if (strcmp(arg1, "sremove") == 0) {
              delete_file(arg2);
          } else {
              printf("Invalid command or arguments. Type 'help' for assistance.\n");
          }
      } else if (sscanf(command, "%s %s %s", arg1, arg2, command) == 3) {
          if (strcmp(arg1, "scopy") == 0) {
              copy_file(arg2,command);
          } else if (strcmp(arg1, "chmod" ) == 0 ){
              int perm = strtol(command, NULL, 8);
              change_permissions(arg2, perm);
          } else {
              printf("Invalid command or arguments. Type 'help' for assistance.\n");
          }
        } else {
            printf("Invalid command format. Type 'help' for assistance.\n");
        }
    }
    
    return 0;
    } 
