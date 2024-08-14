#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char *get_next_line(int fd);
static char *read_file(int fd, char *buffer);
static grab_line( char *buffer);
static grab_rest(char *buffer);

