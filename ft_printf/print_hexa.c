/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:28:03 by asablayr          #+#    #+#             */
/*   Updated: 2019/11/24 13:20:13 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	get_len_hex(unsigned long n)
{
	int	i;

	i = 1;
	while (n / 16 > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char		*print_hexa_min(unsigned long nb)
{
	int		c_len;
	char	*conv;

	c_len = get_len_hex(nb);
	if (!(conv = (char *)malloc(sizeof(char) * (c_len + 1))))
		return (NULL);
	conv[c_len--] = '\0';
	while (c_len >= 0)
	{
		if (nb % 16 > 9)
			conv[c_len--] = nb % 16 + 'a' - 10;
		else
			conv[c_len--] = nb % 16 + '0';
		nb /= 16;
	}
	return (conv);
}

static char	*print_hexa_maj(unsigned long n)
{
	int		c_len;
	char	*conv;

	c_len = get_len_hex(n);
	if (!(conv = (char *)malloc(sizeof(char) * (c_len + 1))))
		return (NULL);
	conv[c_len--] = '\0';
	while (c_len >= 0)
	{
		if (n % 16 > 9)
			conv[c_len--] = n % 16 + 'A' - 10;
		else
			conv[c_len--] = n % 16 + '0';
		n /= 16;
	}
	return (conv);
}

char		*print_hexa(t_flag flags)
{
	char	*str;
	char	*s;
	int		len;

	if (flags.conv == 'x')
		str = print_hexa_min((unsigned long)flags.arg);
	else
		str = print_hexa_maj((unsigned long)flags.arg);
	len = ft_strlen(str);
	if (len < flags.prec)
	{
		if (!(s = (char *)malloc(sizeof(char) * (flags.prec - len + 1))))
			return (NULL);
		s[flags.prec - len] = '\0';
		ft_memset(s, '0', flags.prec - len);
		str = ft_strjoin(s, str);
	}
	else if (flags.prec == 0 && *str == '0')
		str = "";
	return ((flags.alt == 1) ? alt_format(str, flags) : format(str, flags));
}
