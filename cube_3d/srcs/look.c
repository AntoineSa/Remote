/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:40:44 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/15 15:05:18 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cube.h"

void	look_right(t_player *p)
{
	p->dir += M_PI / 6;
}

void	look_left(t_player *p)
{
	p->dir -= M_PI / 6;
}

void	reset_dir(double *d)
{
	if (*d > 2 * M_PI)
		*d -= 2 * M_PI;
	if (*d < 0)
		*d += 2 * M_PI;
}
