/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 10:43:55 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/11 16:22:40 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cube.h"
#include "libft.h"
#include <stdio.h>

static void	get_map(t_settings *set, int fd, char *str)
{
	char	*s2;

	s2 = NULL;
	str = ft_strf1join(str, "\n");
	while (get_next_line(fd, &s2))//no malloc s2
	{
		s2 = ft_strf1join(s2, "\n");
		str = ft_strjoin(str, s2);//no free
	}
	if (*s2 != '\n')
		str = ft_strjoin(str, s2);// no free
	set->map = ft_split(str, '\n');
	free(str);
}

static char	*fill_fields(t_settings *set, int fd, char *str)
{
	
	while (get_next_line(fd, &str))
	{
		if (*str == '1' || *str == '0')
			return (str);;
		if (*str == 'R')
			get_res(&set->res_x, &set->res_y, str);
		else if (*str == 'N')
			set->t_n = get_text(str + 2);
		else if (*str == 'E')
			set->t_e = get_text(str + 2);
		else if (*str == 'S' && *(str + 1) == 'O')
			set->t_s = get_text(str + 2);
		else if (*str == 'W')
			set->t_w = get_text(str + 2);
		else if (*str == 'S')
			set->t_sp = get_text(str + 1);
		else if (*str == 'F')
			get_color(set->c_f, str);
		else if (*str == 'C')
			get_color(set->c_c, str);
	}
	return (str);
}

void	get_settings(t_settings *set, int fd)
{
	char	*str;

	str = NULL;
	init_set(set);
	str = fill_fields(set, fd, str);
	get_map(set, fd, str);
}
