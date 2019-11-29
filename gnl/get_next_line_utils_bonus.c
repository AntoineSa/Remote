/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 10:32:58 by asablayr          #+#    #+#             */
/*   Updated: 2019/11/07 11:19:45 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != c)
		s++;
	if (c != '\0' && *s == '\0')
		return (NULL);
	return (s);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(str = (char *)malloc(ft_strlen(s1) + BUFFER_SIZE + 1)))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;

	if (!(str = (char *)malloc(sizeof(str) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[start + i] && len > i)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	if (s[start + i] != '\n')
		free(s);
	return (str);
}

t_list	*lst_new(int fd)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->s = (char *)malloc(1)))
		return (NULL);
	*new->s = '\0';
	new->fd = fd;
	new->next = NULL;
	return (new);
}
