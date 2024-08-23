/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:23:06 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/08/23 11:52:04 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*grab_rest(char *buffer)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	temp = malloc(ft_strlen(buffer) - i + 1);
	if (!temp)
		return (NULL);
	if (buffer[i] == '\0')
		return (NULL);
	else
	{
		i++;
		while (buffer[i])
		{
			temp[j++] = buffer[i++];

		}
	}
	temp[j] = '\0';
	return (temp);
}
static char	*grab_line(char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = malloc(sizeof(char) * ft_strlen(buffer) + 1);
	if (!temp)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		temp[i] = buffer[j];
		i++;
		j++;
	}
	if (buffer[i] == '\n')
	{
		temp[i] = buffer[j];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}
static char	*read_file(int fd, char *buffer)
{
	char	*temp;
	int		bytes;
	int		i;
	int		flag;

	flag = 0;
	temp = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!temp)
		return (NULL);
	temp[0] = '\0';
	bytes = 1;
	while (flag == 0 && bytes > 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(temp);
			return (NULL);
		}
		flag = ft_strchr(temp, '\n');
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (buffer == NULL)
        	return (NULL);
	line = grab_line(buffer);
	buffer = grab_rest(buffer);
	if (buffer == NULL)
		return (NULL);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	/*         printf("line %s\n", line);
			free(line);
			line = get_next_line(fd);
			printf("line %s\n", line);
			free(line);
			line = get_next_line(fd);
			printf("line %s\n", line);
			free(line);
			line = get_next_line(fd);
			printf("line %s\n", line);
			free(line); */
	while (line != NULL)
	{
		printf("line %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	//free(line);
	close(fd);
}
