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
static char *grab_line( char *buffer);
static char *grab_rest(char *buffer);
static int ft_strlen(char *str)
#endif

