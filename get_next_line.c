/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:23:06 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/08/14 15:00:43 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GET_NEXT_LINE.H"

static int  grab_rest(char *buffer)
{
        char *temp;
        int i;
        int j;

        i = 0;
        j = 0;
        while(buffer[i] != '\n' ||buffer[i] != '\0')
        i++;
        if(buffer[i] == '\n')
        {
         i++;       
        }
        while(buffer[i] != '\0' )
        {
         temp[j++] = buffer[i++];      
        }
        temp[j] = '\0';
        return(temp);
        
}
static grab_line( char *buffer)
{
        char *temp;
        int i;
        int j;

        i = 0;
        j = 0;
        while(buffer[i] != '\n' || buffer[i] != '\0'){
                buffer[i++] == temp[j++];
        }
        
        if(buffer == '\n')
                buffer[i] == temp[j];
        j++;
        temp[j] = '\0';
        return (temp);
}
static char *read_file(int fd, char *buffer)
{
        char *temp;
        int bytes;
        int i;
        int a;

        i = 0;
        a = 0;
        temp = malloc(BUFFER_SIZE *(sizeof (char)));
        if(!temp){
                free(temp);
                return(NULL);
        }
        bytes = 1;
        while(!strchr(temp, '\n' && bytes != 0))
        {
                temp = read(fd,temp,BUFFER_SIZE);
                if(bytes < 0){
                        free(temp);
                        return (NULL);
                }
                buffer[bytes] = '\0';
                strjoin(buffer,temp);
        }
        return(buffer);
        }

char *get_next_line(int fd)
{
        static char *buffer;
        char *line;
        int i;

        i = 0;
        if(fd < 0 || BUFFER_SIZE <= 0)
                return (NULL);
        buffer = read_file(buffer, fd);
        if(buffer == NULL)
                return (NULL);
        line = grab_Line(buffer);
        buffer = grab_rest(buffer);
        return(line);  
}

int main(void)
{
        int fd;
        char *line;

        fd = fopen("text.txt","r");
        if(!fd)
        {
                printf("failed to read file");
                return(1);
        }
        while(line = get_next_line(fd))
        {
                printf("%s",line);
        }
        return 0;
}
