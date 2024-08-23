/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:42:38 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/08/23 11:47:15 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	a;
	char	*str3;

	i = 0;
	a = 0;
	if (!s2)
		return (NULL);
	str3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str3)
		return (NULL);
	while (s1 != NULL && s1[a])
	{
		str3[i++] = s1[a++];
	}
	free(s1);
	a = 0;
	while (s2 != NULL && s2[a])
	{
		str3[i++] = s2[a++];
		
	}
	str3[i] = '\0';
	//free(str3);
	return (str3);
}

int	ft_strchr(const char *str, char c)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}
