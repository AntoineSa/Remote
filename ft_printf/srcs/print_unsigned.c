/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:44:10 by asablayr          #+#    #+#             */
/*   Updated: 2019/12/05 17:16:57 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	get_len_u(unsigned long n)
{
	int	i;

	i = 1;
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*print_nb_u(unsigned int n)
{
	int		i;
	char	*str;

	i = get_len_u(n);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	while (n / 10 > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = n % 10 + '0';
	return (str);
}

int			print_unsigned_int(t_flag flags)
{
	char	*str;
	char	*s;
	int		len;

	str = print_nb_u((unsigned int)flags.arg);
	len = ft_strlen(str);
	if (flags.prec > len)
	{
		if (!(s = (char *)malloc(flags.prec - len + 1)))
			return (0);
		ft_memset(s, '0', flags.prec - len);
		s[flags.prec - len] = '\0';
		str = ft_strjoin(s, str);
	}
	else if (flags.prec == 0 && *str == '0')
		str = ft_substr(str, 0, 0);
	return (format(str, flags));
}
