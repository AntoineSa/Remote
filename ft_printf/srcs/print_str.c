/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:09:47 by asablayr          #+#    #+#             */
/*   Updated: 2019/12/10 11:18:14 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int				print_str(t_flag flags)
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
	else if (flags.conv == 'c')
	{
		str = ft_calloc(1, 2);
		ft_memcpy(str, &flags.arg, 1);
		str[1] = '\0';
	}
	if (!str)
		return (format_char(ft_strjoin("(null)", "\0"), flags));
	return (format_char(str, flags));
}

int				print_perc(t_flag flags)
{
	char	*str;
	char	*s;
	char	c;

	str = ft_strjoin("%", "");
	if (flags.size > 0)
	{
		s = ft_calloc(1, flags.size);
		c = flags.pad == 1 ? '0' : ' ';
		ft_memset(s, c, flags.size - 1);
		str = flags.pad != 2 ? ft_strffjoin(s, str) : ft_strffjoin(str, s);
	}
	return (f_write(1, str, ft_strlen(str)));
}

int				print_addr(t_flag flags)
{
	char	*str;
	char	*s;

	s = ft_strjoin("0x", "\0");
	if (flags.arg == 0 && flags.prec == 0)
		return (format(s, flags));
	str = print_hexa_min((unsigned long)flags.arg);
	str = ft_strffjoin(s, str);
	return (format(str, flags));
}
