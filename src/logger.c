#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../include/logger.h"

void write_log(const char* log_file, const char* message) {
    FILE* file = fopen(log_file, "a"); //append mode
    if ( file == NULL ) {
      perror("Error opening log file.");
      return;
    }
    
    time_t now = time(NULL);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&now));
    
    //writing log entry
    fprintf(file, "[%s] %s\n", time_str, message);
    fclose(file);
    
    printf("Log written: %s\n", message);
    
}

void read_logs(const char* log_file) {
    FILE* file = fopen(log_file,"r");
    if (file == NULL) {
      perror("Error opening file");
      return;
    }
    
    char buffer[1024];
    printf("Logs from %s:\n", log_file);
    while (fgets(buffer,sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}
