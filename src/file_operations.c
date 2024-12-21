#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/file_operations.h"


void read_file(const char* path){
    int fd = open(path, O_RDONLY); //opens the files only read mode
    if (fd == -1) {
        perror ("Error opening file");
        return;
    }
    char buffer[1024];
    ssize_t bytes_read;
    
    printf("Content of %s:\n", path);
    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0 ){ //read reads the data from file and loads to buffer
        buffer[bytes_read] = '\0'; // null terminate the buffer
        printf("%s", buffer);
    }
    
    if (bytes_read == -1) {
        perror("Error reading file");
    }
    close(fd); 
}

void write_file(const char* path, const char* content){
    //O_WRONLY: opens file only write mode O_CREAT:creates file if not exist O_APPEND:if file exist,appends 
    //the content at the end of file
    int fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
      perror("Error opening file!");
      return;
    }
    
    ssize_t bytes_written = write (fd, content, sizeof(char) * strlen(content));
    if (bytes_written == -1) {
      perror("Error writing to file");
    } else {
      printf("Successfully wrote to the file: %s\n", path);
    }
    close(fd);
}

void copy_file(const char* src, const char* dest) {
    int src_fd = open(src, O_RDONLY);
    if (src_fd == -1) {
      perror("Error opening source file");
      return;
    }
    
  int dest_fd = creat(dest, 0644);
  if (dest_fd == -1) {
    perror("Error creating destination file");
    close(src_fd);
    return;
  }
  
  char buffer[1024];
  ssize_t bytes_read;
  while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
    if (write(dest_fd, buffer, bytes_read) != bytes_read) {
      perror("Error writing to destination file");
      break;
    }
  }
  
    close(src_fd);
    close(dest_fd);
}

void delete_file(const char* path) {
    if (unlink(path) == -1) {
        perror("Error deleting file!");
    } else {
        printf("File deleted successfully: %s\n",path);
    }
}
