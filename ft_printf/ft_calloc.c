/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:19:34 by asablayr          #+#    #+#             */
/*   Updated: 2019/11/18 15:21:37 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count <= 0 || size <= 0)
	{
		count = 1;
		size = 1;
	}
	if (!(mem = malloc(count * size)))
		return (NULL);
	ft_memset(mem, 0, (count * size));
	return (mem);
}
