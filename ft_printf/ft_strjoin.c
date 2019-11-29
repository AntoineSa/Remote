/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:34:27 by asablayr          #+#    #+#             */
/*   Updated: 2019/11/29 14:29:31 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
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
		str[i++] = *(s2++);
	str[i] = '\0';
	return (str);
}

char	*ft_strfjoin(char *s1, char *s2)
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
	while (*s2 != '\0')
		str[i++] = *(s2++);
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
	while (*s2 != '\0')
		str[i++] = *(s2++);
	free(s2);
	str[i] = '\0';
	return (str);
}
