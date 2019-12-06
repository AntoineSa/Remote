/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:28:55 by asablayr          #+#    #+#             */
/*   Updated: 2019/12/05 16:57:46 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *str_d;
	unsigned char *str_s;

	if (!src && !dst)
		return (NULL);
	str_d = (unsigned char *)dst;
	str_s = (unsigned char *)src;
	while (n > 0)
	{
		*str_d = *str_s;
		str_d++;
		str_s++;
		n--;
	}
	return (dst);
}

void	*ft_merge(void *dst, size_t s_d, void *src, size_t s_s)
{
	unsigned char	*str_d;
	unsigned char	*str_t;
	int				i;

	i = 0;
	str_t = (unsigned char *)dst;
	str_d = (unsigned char *)malloc(s_d + s_s + 1);
	while (i < s_d)
	{
		str_d[i] = str_t[i];
		i++;
	}
	str_t = (unsigned char *)src;
	while (i - s_d < s_s)
	{
		str_d[i] = str_t[i - s_d];
		i++;
	}
	str_d[i] = '\0';
	return (str_d);
}
