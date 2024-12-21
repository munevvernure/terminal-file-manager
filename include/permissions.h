#ifndef PERMISSIONS_H
#define PERMISSIONS_H
#include <sys/types.h>

void check_permissions(const char* path);
void change_permissions(const char* path, mode_t mode);

#endif
