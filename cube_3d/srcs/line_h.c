/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_h.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:37:11 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/14 16:41:50 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cube.h"
#include "libft.h"
#include <stdio.h>

float	*get_h_const(float dir)
{
	float	x_a;
	float	y_a;
	float	*ray;

	ray = ft_calloc(sizeof(float), 2);
	if (dir == 0 || dir == M_PI)
		y_a = 0;
	else if (dir > 0 && dir < M_PI)
		y_a = 1;
	else
		y_a = -1;
	if (dir == 0)
		x_a = 1;
	else if (dir == M_PI_2 || dir == 3 * M_PI_2)
		x_a = 0;
	else if (dir == M_PI)
		x_a = -1;
	else if ((dir > 0 && dir < M_PI_2) || dir > 3 * M_PI_2)
		x_a = y_a / tan(dir);
	else
		x_a = -y_a / tan(dir);
	ray[0] = x_a;
	ray[1] = y_a;
	return (ray);
}

float	*get_v_const(float dir)
{
	float	x_a;
	float	y_a;
	float	*ray;

	ray = ft_calloc(sizeof(float), 2);
	if (dir == M_PI_2 || dir == 3 * M_PI_2)
		x_a = 0;
	else if ((dir >= 0 && dir < M_PI_2) || (dir > 3 * M_PI_2 && dir <= 2 * M_PI))
		x_a = 1;
	else
		x_a = -1;
	if (dir == 0 || dir == M_PI)
		y_a = 0;
	else if (dir == M_PI_2)
		y_a = 1;
	else if (dir == 3 * M_PI_2)
		y_a = -1;
	else if ((dir > 0 && dir < M_PI_2) || dir > 3 * M_PI_2)
		y_a = x_a / tan(dir);
	else
		y_a = -x_a / tan(dir);
	ray[0] = x_a;
	ray[1] = y_a;
	return (ray);
}

int	check_w(t_player p, t_settings s, float x, float y)
{
	if (p.dir > M_PI)
		y = (int)y - 1;
	else
		y = (int)y;
	if (p.dir > M_PI_2 && p.dir < 3 * M_PI_2)
		x = (int)x - 1;
	else
		x = (int)x;
	return(s.map[(int)y][(int)x] - 48);
}
