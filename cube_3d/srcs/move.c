/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:18:45 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/15 14:40:30 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

void	move_front(t_player *p)
{
	p.x += cos(p.dir) * SPEED;
	p.y += sin(p.dir) * SPEED;
}
void	move_back(t_player *p)
{
	p.x -= cos(p.dir) * SPEED;
	p.y -= sin(p.dir) * SPEED;
}

void	move_right(t_player *p)
{
	p.x += sin(p.dir) * SPEED;
	p.y += cos(p.dir) * SPEED;
}

void	move_left(t_player *p)
{
	p.x -= sin(p.dir) * SPEED;
	p.y -= cos(p.dir) * SPEED;
}
