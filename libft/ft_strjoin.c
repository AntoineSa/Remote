/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:34:27 by asablayr          #+#    #+#             */
/*   Updated: 2019/12/22 17:08:34 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		n;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	n = 0;
	while (s1[n] != '\0')
		str[i++] = s1[n++];
	while (*s2 != '\0')
	{
		str[i++] = *(s2++);
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strffjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		n;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	n = 0;
	while (s1[n] != '\0')
		str[i++] = s1[n++];
	free(s1);
	n = 0;
	while (s2[n] != '\0')
		str[i++] = s2[n++];
	str[i] = '\0';
	free(s2);
	return (str);
}

char	*ft_strf1join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		n;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	n = 0;
	while (s1[n] != '\0')
		str[i++] = s1[n++];
	free(s1);
	n = 0;
	while (s2[n] != '\0')
		str[i++] = s2[n++];
	str[i] = '\0';
	return (str);
}

char	*ft_strf2join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		n;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	n = 0;
	while (s1[n] != '\0')
		str[i++] = s1[n++];
	n = 0;
	while (s2[n] != '\0')
		str[i++] = s2[n++];
	str[i] = '\0';
	free(s2);
	return (str);
}
