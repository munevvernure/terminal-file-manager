#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../include/logger.h"

void write_log(const char* log_file, const char* operation, const char* result) {
    // Log format: [DATE TIME] OPERATION RESULT
    time_t now = time(NULL);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&now));

   
    char log_entry[512];
    snprintf(log_entry, sizeof(log_entry), "[%s] %s: %s\n", time_str, operation, result);

   // openning log file, if not it creates
    int fd = open(log_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Error opening log file");
        return;
    }

    if (write(fd, log_entry, strlen(log_entry)) == -1) {
        perror("Error writing to log file");
    }

    close(fd);
}


void read_logs(const char* log_file) {
    char buffer[1024];
    FILE* file = fopen(log_file,"r");
    if (file == NULL) {
      perror("Error opening file");
      return;
    }
    
    printf("Logs from %s:\n", log_file);
    while (fgets(buffer,sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
    
}
