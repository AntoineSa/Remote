/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:41:19 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/05 18:35:58 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

void	get_color(char obj, t_settings *set, char *str)
{
	int text[3];

	text[0] = ft_atoi(++str);
	while (*str != ',')
		str++;
	text[1] = ft_atoi(++str);
	while (*str != ',')
		str++;
	text[2] = ft_atoi(++str);
	if (obj == 'F')
		set->c_f = text;
	else
		set->c_c = text;
}

void	get_text(char *text, char *str)
{
	while (*str == ' ')
			str++;
	text = str;
}

void	get_res(int *res_x, int *res_y, char *str)
{
		*res_x = ft_atoi(++str);
		while (*str == ' ')
			str++;
		while (*str >= '0' && *str <= '9')
			str++;
		*res_y = ft_atoi(str);
}

void	init_set(t_settings *set)
{
	int	c[3];
	int	f[3];

	set->res_x = 90;
	set->res_y = 90;
	set->t_n = "../textures/t_n";
	set->t_e = "../textures/t_e";
	set->t_s = "../textures/t_s";
	set->t_w = "../textures/t_w";
	set->t_sp = "../textures/t_sp";
	c[0] = 116;
	c[1] = 102;
	c[2] = 59;
	f[0] = 135;
	f[1] = 206;
	f[2] = 235;
}
