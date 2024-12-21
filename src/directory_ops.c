#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../include/directory_ops.h"

void list_directory(const char* path) {
    struct dirent* entry;
    DIR* dir = opendir(path);
    
    if (dir == NULL) {
      perror("Error opening directory");
      return;
    }

    printf("Contents of directory '%s' :\n", path);
    while((entry = readdir(dir)) != NULL) {
      printf("%s\n", entry -> d_name);
    }
    closedir(dir);
}

void create_directory(const char* path) {
    if (mkdir(path,0755) == 0) {
      printf("Directory '%s' created successfully. \n", path);
    } else {
      perror("Error creating directory");
    }
}

void delete_directory(const char* path) {
    if (rmdir(path) == 0) {
      printf("Directory '%s' deleted successfully. \n", path);
    } else {
      perror("Error deleting directory.");
    }
}
