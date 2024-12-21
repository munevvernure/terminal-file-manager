#ifndef LOGGER_H
#define LOGGER_H

void write_log(const char* log_file, const char* operation, const char* result);
void read_logs(const char* log_file);

#endif
