/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 08:19:11 by asablayr          #+#    #+#             */
/*   Updated: 2019/11/26 16:27:04 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_alt(char *s, int *flag)
{
	while (*(++s) == '0' || *s == '-' || *s == '+' || *s == ' ' || *s == '#')
		if (*s == '#')
			*flag = 1;
}

int		check_conv(char c, char *conv)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
	{
		*conv = c;
		return (1);
	}
	*conv = '%';
	return (0);
}

int		check_nb(char *s, int *flag)
{
	int	i;

	i = 0;
	if (*s == '*')
	{
		*flag = -1;
		return (1);
	}
	else if (*s >= '0' && *s <= '9')
		*flag = ft_atoi(s);
	else
		*flag = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (i);
}

int		check_padding(char *s, t_flag *flags)
{
	int i;
	int	neg;
	int	plus;

	i = 0;
	neg = 0;
	plus = 0;
	while (s[++i] == '0' || s[i] == '-' || s[i] == '+' ||
		s[i] == ' ' || s[i] == '#')
	{
		if (s[i] == '0')
			flags->pad = 1;
		if (s[i] == '-')
			neg = 1;
		if (s[i] == ' ')
			flags->spa = 1;
		if (s[i] == '+')
			plus = 1;
	}
	flags->spa = plus == 1 ? 2 : flags->spa;
	if (flags->spa > 0 || flags->alt > 0)
		flags->pad = 0;
	flags->pad = neg == 1 ? 2 : flags->pad;
	return (i);
}
