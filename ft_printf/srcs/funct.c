/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:09:47 by asablayr          #+#    #+#             */
/*   Updated: 2019/12/04 12:06:21 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

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

char			*print_str(t_flag flags)
{
	char *str;

	if (flags.conv == 's')
	{
		if (flags.prec >= 0)
		{
			if (!flags.arg)
				str = ft_substr("(null)", 0, flags.prec);
			else
				str = ft_substr(flags.arg, 0, flags.prec);
		}
		else
			str = ft_substr(flags.arg, 0, ft_strlen(flags.arg));
	}
	else if (flags.conv == 'c' || flags.conv == '%')
	{
		str = calloc(1, 2);
		*str = '%';
		if (flags.conv == 'c')
			ft_memcpy(str, &flags.arg, 1);
		str[1] = '\0';
	}
	if (!str)
		return (format_char(ft_strjoin("(null)", "\0"), flags));
	return (format_char(str, flags));
}

char			*print_addr(t_flag flags)
{
	char	*str;
	char	*s;

	s = "0x\0";
	str = print_hexa_min((unsigned long)flags.arg);
	str = ft_strf2join(s, str);
	return (format(str, flags));
}

char			*do_shit(va_list aq, t_flag *flags, char *str)
{
	char	*buff;
	t_aff	*tab;

	buff = ft_calloc(1, 1);
	tab = tab_init();
	while (ft_strchr(str, '%'))
	{
		buff = ft_strffjoin(buff, ft_substr(str, 0, ft_strchr(str, '%') - str));
		str = ft_strchr(str, '%');
		str += get_flags(str, flags);
		get_arg(aq, flags->conv, flags);
		buff = ft_strffjoin(buff, tab[(int)flags->conv](*flags));
	}
	free(tab);
	if (*str)
		buff = ft_strf1join(buff, str);
	return (buff);
}
