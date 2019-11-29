/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:03:35 by asablayr          #+#    #+#             */
/*   Updated: 2019/11/29 14:26:05 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	get_arg(va_list aq, char c, t_flag *flags)
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

char	*format_neg(char *buff, t_flag flags)
{
	char	*s;
	int		len;

	len = flags.spa == 0 ? ft_strlen(buff) + 1 : ft_strlen(buff) + 2;
	if (flags.size <= len)
		return (ft_strjoin("-", buff));
	s = ft_calloc(1, ((flags.size - len) + 1));
	ft_memset(s, ' ', flags.size - len);
	if (flags.pad == 1)
	{
		ft_memset(s, '0', flags.size - len);
		buff = ft_strjoin(s, buff);
		return (flags.spa > 0 ? ft_strjoin(" -", buff) : ft_strjoin("-", buff));
	}
	else
		buff = ft_strjoin("-", buff);
	if (flags.spa > 0)
		buff = ft_strjoin(buff, " ");
	return (flags.pad == 2 ? ft_strjoin(buff, s) : ft_strjoin(s, buff));
}

char	*format(char *buff, t_flag flags)
{
	char	*s;
	char	c;
	int		len;

	len = (flags.spa == 0) ? ft_strlen(buff) : ft_strlen(buff) + 1;
	if (flags.size <= len)
	{
		if (flags.spa != 2 && *buff != '-')
			return (flags.spa == 1 ? ft_strjoin(" ", buff) : buff);
		return (ft_strjoin("+", buff));
	}
	s = ft_calloc(1, (flags.size - len + 1));
	c = (flags.pad == 1) ? '0' : ' ';
	ft_memset(s, c, flags.size - len);
	if (flags.spa == 1)
		buff = ft_strjoin(" ", buff);
	if (flags.spa == 2)
		buff = ft_strjoin("+", buff);
	buff = (flags.pad == 2) ? ft_strjoin(buff, s) : ft_strjoin(s, buff);
	return (buff);
}

char	*format_char(char *buff, t_flag flags)
{
	char	*s;
	int		len;

	len = ft_strlen(buff);
	if (flags.size <= len)
		return (buff);
	s = ft_calloc(1, flags.size - len + 1);
	if (flags.conv == '%' && flags.pad == 1)
		ft_memset(s, '0', flags.size - len);
	else
		ft_memset(s, ' ', flags.size - len);
	buff = (flags.pad == 2) ? ft_strjoin(buff, s) : ft_strjoin(s, buff);
	return (buff);
}

char	*alt_format(char *buff, t_flag flags)
{
	if ((char)flags.arg == '\0')
	{
		if (flags.prec >= 0)
		{
			buff = ft_calloc(1, flags.prec);
			ft_memset(buff, '0', flags.prec);
		}
		else
			buff = "0";
		return (format(buff, flags));
	}
	if (flags.conv == 'X')
		buff = ft_strjoin("0X", buff);
	else
		buff = ft_strjoin("0x", buff);
	return (format(buff, flags));
}
