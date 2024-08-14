#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char *get_next_line(int fd);
static char *read_file(int fd, char *buffer);
static int grab_line( char *buffer);
static int grab_rest(char *buffer);
#endif

