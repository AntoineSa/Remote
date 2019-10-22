/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:29:24 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/22 14:27:37 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str_d;
	unsigned char	*str_s;

	str_d = (unsigned char *)dst;
	str_s = (unsigned char *)src;
	if (!src || !dst)
		return (NULL);
	if (str_d > str_s)
	{
		while (len > 0)
		{
			len--;
			str_d[len] = str_s[len];
		}
	}
	else
	{
		while (len > 0)
		{
			*str_d = *str_s;
			str_d++;
			str_s++;
			len--;
		}
	}
	return (dst);
}
