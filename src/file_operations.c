#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/file_operations.h"

void create_file(const char* path) {
    // O_CREAT: creates file if it doesn't exist
    // O_EXCL: ensures file doesn't already exist (returns error if it does)
    // 0644 permissions: rw-r--r-- (owner can read/write, others can read)
    int fd = open(path, O_CREAT | O_EXCL, 0644);
    
    if (fd == -1) {
        perror("Error creating file");
        return;
    }
    
    printf("File created successfully: %s\n", path);
    close(fd);
}

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
    
    printf("Content to write: '%s' (length: %zu)\n", content, strlen(content)); // Debugging output
   
    int fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
      perror("Error opening file!");
      return;
    }
    
    ssize_t bytes_written = write(fd, content, strlen(content));
    if (bytes_written == -1) {
      perror("Error writing to file");
    } else {
      write(fd, "\n", 1); //adding new line after writing
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
void move_file(const char *src, const char *dest) {
    if (rename(src, dest) == 0 ) {
      printf("File moved successfully from %s to %s\n", src, dest);
    } else{
      perror("Error moving file");
    }
} 


