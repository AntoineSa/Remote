/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:29:35 by asablayr          #+#    #+#             */
/*   Updated: 2019/10/18 12:07:03 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	unsigned char	check;

	str = (char *)s;
	check = (unsigned char)c;
	while (*str != '\0' && *str != c && n > 0)
	{
		str++;
		n--;
	}
	if (n == 0)
		return (NULL);
	return (str);
}
