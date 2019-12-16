/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:29:54 by asablayr          #+#    #+#             */
/*   Updated: 2019/12/12 17:56:42 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

static void	flag_init(t_flag *flags)
{
	flags->pad = 0;
	flags->spa = 0;
	flags->size = 0;
	flags->prec = -2;
	flags->alt = 0;
	flags->conv = '\0';
}

int			get_flags(const char *s, t_flag *flags)
{
	int		i;
	char	*str;

	str = (char *)s;
	flag_init(flags);
	check_alt(str, &flags->alt);
	i = check_padding(str, flags);
	i += check_nb(&str[i], &flags->size);
	if (str[i] == '.' && i++)
		i += check_nb(&str[i], &flags->prec);
	return (check_conv(str[i], &flags->conv) == 1 ? i + 1 : 1);
}
