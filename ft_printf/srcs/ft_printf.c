/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:45:31 by asablayr          #+#    #+#             */
/*   Updated: 2019/12/05 17:16:07 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

static t_aff	*tab_init(void)
{
	t_aff	*tab;

	if (!(tab = (t_aff *)malloc(sizeof(void *) * 255)))
		return (NULL);
	tab['%'] = print_str;
	tab['%'] = print_str;
	tab['c'] = print_str;
	tab['s'] = print_str;
	tab['p'] = print_addr;
	tab['d'] = print_int;
	tab['i'] = print_int;
	tab['u'] = print_unsigned_int;
	tab['x'] = print_hexa;
	tab['X'] = print_hexa;
	return (tab);
}

static void		get_arg(va_list aq, char c, t_flag *flags)
{
	if (c != '%')
	{
		if (flags->size == -1)
			flags->size = va_arg(aq, int);
		if (flags->prec == -1)
			flags->prec = va_arg(aq, int);
		flags->arg = va_arg(aq, void *);
	}
}

static int		convert(va_list aq, t_flag *flags, char *str)
{
	char	*s;
	int		nb;
	t_aff	*tab;

	s = ft_strchr(str, '%');
	tab = tab_init();
	nb = 0;
	while ((s = ft_strchr(str, '%')))
	{
		nb += write(1, str, s - str);
		s += get_flags(s, flags);
		get_arg(aq, flags->conv, flags);
		nb += tab[(int)flags->conv](*flags);
		str = s;
	}
	free(tab);
	nb += write(1, str, ft_strlen(str));
	return (nb);
}

int				ft_printf(const char *str, ...)
{
	int		nb;
	t_flag	*flags;
	va_list	aq;

	if (!(ft_strchr(str, '%')))
		return (write(1, str, ft_strlen(str)));
	va_start(aq, str);
	if (!(flags = (t_flag *)malloc(sizeof(t_flag))))
		return (0);
	nb = convert(aq, flags, (char *)str);
	free(flags);
	va_end(aq);
	return (nb);
}
