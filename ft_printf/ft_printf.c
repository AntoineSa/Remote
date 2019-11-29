/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:45:31 by asablayr          #+#    #+#             */
/*   Updated: 2019/11/26 16:54:46 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int		nb;
	t_flag	*flags;
	va_list	aq;
	char	*buff;

	if (!(ft_strchr(str, '%')))
		return (write(1, str, ft_strlen(str)));
	va_start(aq, str);
	buff = ft_calloc(1, 1);
	if (!(flags = (t_flag *)malloc(sizeof(t_flag))))
		return (0);
	buff = do_shit(aq, flags, (char *)str);
	free(flags);
	va_end(aq);
	nb = write(1, buff, ft_strlen(buff));
	free(buff);
	return (nb);
}
