#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

void create_file(const char* path);
void read_file(const char* path);
void write_file(const char* path, const char* content);
void copy_file(const char* src, const char* dest);
void delete_file(const char* path);
void move_file(const char *src, const char *dest);


#endif
