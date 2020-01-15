/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:41:19 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/11 16:50:33 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	get_color(int *set, char *str)
{
	set[0] = ft_atoi(++str);
	while (*str != ',')
		str++;
	set[1] = ft_atoi(++str);
	while (*str != ',')
		str++;
	set[2] = ft_atoi(++str);
}

char	*get_text(char *str)
{
	while (*str == ' ')
			str++;
	return (str);
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
	if (!(set->c_f = (int*)malloc(sizeof(int) * 3)))
		return ;
	if (!(set->c_c = (int*)malloc(sizeof(int) * 3)))
		return ;
	set->res_x = 320;
	set->res_y = 200;
	set->t_n = "../textures/t_n";
	set->t_e = "../textures/t_e";
	set->t_s = "../textures/t_s";
	set->t_w = "../textures/t_w";
	set->t_sp = "../textures/t_sp";
	set->c_c[0] = 116;
	set->c_c[1] = 102;
	set->c_c[2] = 59;
	set->c_f[0] = 135;
	set->c_f[1] = 206;
	set->c_f[2] = 235;
}
