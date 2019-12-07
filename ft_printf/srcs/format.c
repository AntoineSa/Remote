/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:03:35 by asablayr          #+#    #+#             */
/*   Updated: 2019/12/06 15:39:40 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	easy_format(t_flag f, char *buff, int len)
{
	if (f.spa != 2)
	{
		if (f.spa == 1)
			return (write(1, ft_strf2join(" ", buff), len));
		else
			return (write(1, buff, len));
	}
	return (write(1, ft_strf2join("+", buff), len));
}

int			format_neg(char *b, t_flag f)
{
	char	*s;
	int		len;

	len = ft_strlen(b) + 1;
	if (f.size <= len)
		return (write(1, ft_strf2join("-", b), len));
	s = ft_calloc(1, ((f.size - len) + 1));
	ft_memset(s, ' ', f.size - len);
	if (f.pad == 1)
	{
		ft_memset(s, '0', f.size - len);
		b = ft_strffjoin(s, b);
		b = f.spa > 0 ? ft_strf2join(" -", b) : ft_strf2join("-", b);
		return (write(1, b, ft_strlen(b)));
	}
	else
		b = ft_strf2join("-", b);
	b = f.pad == 2 ? ft_strffjoin(b, s) : ft_strffjoin(s, b);
	return (write(1, b, ft_strlen(b)));
}

int			format(char *buff, t_flag flags)
{
	char	*s;
	char	*c;
	int		len;

	len = (flags.spa == 0) ? ft_strlen(buff) : ft_strlen(buff) + 1;
	if (flags.size <= len)
		return (easy_format(flags, buff, len));
	s = ft_calloc(1, (flags.size - len + 1));
	c = (flags.pad == 1) ? "0" : " ";
	ft_memset(s, *c, flags.size - len);
	c = (flags.spa > 1) ? "+" : " ";
	if (flags.pad != 1 && flags.spa != 0)
		buff = ft_strf2join(c, buff);
	buff = (flags.pad == 2) ? ft_strffjoin(buff, s) : ft_strffjoin(s, buff);
	if (flags.pad == 1 && flags.spa != 0)
		buff = ft_strf2join(c, buff);
	return (write(1, buff, ft_strlen(buff)));
}

int			format_char(char *buff, t_flag f)
{
	char	*s;
	int		len;
	int		l;

	if (f.conv == 'c' && *buff == '\0')
		len = 1;
	else
		len = ft_strlen(buff);
	if (f.size <= len)
		return (write(1, buff, len));
	l = f.size - len;
	s = ft_calloc(1, l + 1);
	if (f.conv == '%' && f.pad == 1)
		ft_memset(s, '0', l);
	else
		ft_memset(s, ' ', l);
	buff = (f.pad == 2) ? ft_merge(buff, len, s, l) : ft_merge(s, l, buff, len);
	return (write(1, buff, l + len));
}

int			alt_format(char *buff, t_flag flags)
{
	if ((char)flags.arg == '\0')
	{
		if (flags.prec >= 0)
		{
			buff = ft_calloc(1, flags.prec);
			ft_memset(buff, '0', flags.prec);
		}
		else
		{
			buff = ft_calloc(1, 2);
			*buff = '0';
		}
		return (format(buff, flags));
	}
	if (flags.conv == 'X')
		buff = ft_strf2join("0X", buff);
	else
		buff = ft_strf2join("0x", buff);
	return (format(buff, flags));
}
