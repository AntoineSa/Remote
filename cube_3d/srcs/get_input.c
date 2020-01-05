/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 10:43:55 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/05 18:48:41 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cube.h"
#include "libft.h"

static void	get_map(t_settings *set, int fd, char *str)
{
	char	*s2;

	s2 = NULL;
	while (get_next_line(fd, &s2))//no malloc s2
		str = ft_strjoin(str, s2);//no free
	if (*s2 != '\n')
		str = ft_strjoin(str, s2);// no free
	set->map = ft_split(str, '\n');
	free(str);
}

static char	*get_settings(t_settings *set, int fd, char *str)
{
	
	while (get_next_line(fd, &str))
	{
		if (*str == '1' || *str == '0')
			return (str);;
		if (*str == 'R')
			get_res(&set->res_x, &set->res_y, str);
		else if (*str == 'N')
			get_text(set->t_n, str + 2);
		else if (*str == 'E')
			get_text(set->t_e, str + 2);
		else if (*str == 'S' && *(str + 1) == 'O')
			get_text(set->t_s, str + 2);
		else if (*str == 'W')
			get_text(set->t_w, str + 2);
		else if (*str == 'S')
			get_text(set->t_sp, str + 1);
		else if (*str == 'F' || *str == 'C')
			get_color(*str, set, str);
	}
	return (str);
}

void	get_input(t_settings *set, int fd)
{
	char	*str;

	str = NULL;
	init_set(set);
	str = get_settings(set, fd, str);
	get_map(set, fd, str);
}
