#include <stdio.h>
#include <sys/stat.h>
#include "../include/permissions.h"

void check_permissions(const char* path) {
    struct stat file_stat;
    
    if (stat(path, &file_stat) == -1 ) {
        perror("Error retrieving permissions");
        return;
    }
    
    printf("Permissions for %s: ", path);
    printf((S_ISDIR(file_stat.st_mode)) ? "d" : "-");
    printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
    printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
    printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
    
}

void change_permissions(const char* path, mode_t mode) {
    if (chmod(path, mode) == 0) {
        printf("Permissions changed successfully for %s\n", path);
    } else {
      perror("Error changing permissions");
    }
}
