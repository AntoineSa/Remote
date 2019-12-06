/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:09:47 by asablayr          #+#    #+#             */
/*   Updated: 2019/12/05 16:50:28 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

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

int				print_addr(t_flag flags)
{
	char	*str;
	char	*s;

	s = "0x\0";
	str = print_hexa_min((unsigned long)flags.arg);
	str = ft_strf2join(s, str);
	return (format(str, flags));
}
