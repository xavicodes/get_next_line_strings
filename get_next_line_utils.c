/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:42:38 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/08/14 15:47:18 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//extra functions.
//STRJOIN - JOINING THE BUFFER TO THE GLOBAL VARIABLE.
//STRCHR - USED TO SEARCH TRUE THE STRING FOR A "\n" and give use a flag 0 or 1. 
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return i;
}
static char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		a;
	char	*str3;

	i = 0;
	a = 0;
	if (!s1 || !s2)
		return (NULL);
	str3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str3)
		return (NULL);
	while (s1[a])
	{
		str3[i] = s1[a];
		i++;
		a++;
	}
	a = 0;
	while (s2[a])
		str3[i++] = s2[a++];
	str3[i] = '\0';
	return (str3);
}



static char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if ((unsigned char)c == 0 || (*str == '\0' && (unsigned char)c == 0))
		return ((char *)&str[i]);
	while (--i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
	}
	return (0);
}