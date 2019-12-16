/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:33:41 by asablayr          #+#    #+#             */
/*   Updated: 2019/12/09 17:19:57 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	get_len(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*print_nb(long n)
{
	int		i;
	char	*str;

	i = get_len(n);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n / 10 > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = n % 10 + '0';
	return (str);
}

int			print_int(t_flag flags)
{
	char	*str;
	char	*s;
	int		len;
	int		neg;

	str = print_nb((int)flags.arg);
	neg = (*str == '-') ? 1 : 0;
	len = (neg == 1) ? ft_strlen(str) - 1 : ft_strlen(str);
	if (neg == 1)
		str = ft_subfstr(str, 1, ft_strlen(str) - 1);
	if (flags.prec > len)
	{
		if (!(s = (char *)malloc(flags.prec - len + 1)))
			return (0);
		ft_memset(s, '0', flags.prec - len);
		s[flags.prec - len] = '\0';
		str = ft_strffjoin(s, str);
	}
	else if (flags.prec == 0 && *str == '0')
		str = ft_subfstr(str, 0, 0);
	return (neg == 1 ? format_neg(str, flags) : format(str, flags));
}
