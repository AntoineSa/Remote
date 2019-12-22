/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 10:43:55 by asablayr          #+#    #+#             */
/*   Updated: 2019/12/22 16:34:44 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cube.h"

static void	set_res(int *res_x, int *res_y, char *str)
{
		set->res_x = ft_atoi(++str);
		while (*str == ' ')
			str++;
		while (*str >= '0' && *str <= '9')
			str++;
		set->res_y = ft_atoi(str);
}

static void	set_text(char *text, char *str)
{
	while (*str == ' ')
			str++;
	text = str;
}

static void	set_color(char obj, t_settings *set, char *str)
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
		c_f = text;
	else
		c_c = text;
}

static char	*load_map(int fd, char *str)
{
	char	*s2;

	get_next_line(fd, s2); //no malloc s2
	str = ft_strjoin(str, s2); //no free
	while (get_next_line(fd, &s2))
		str = ft_strjoin(str, s2); //no free
	if (s2 != "\n")
		str = ft_strjoin(str, s2); //same
	free(s2);
	return (str);
}

void	get_map(s_setting *set, int fd, char *str)
{
	str = load_map(fd, str); // ! leaks
	set->map = ft_split(str, '\n');
	free(str);
}

char	*get_settings(s_settings *set, int fd)
{
	char	*str;

	while (get_next_line(fd, &str))
	{
		if (*str == '1' || *str == '0')
			return ;
		if (*str == 'R')
			set_res(set->res_x, set->res_y, str);
		else if (*str == 'N')
			set_text(set->t_n, str + 2);
		else if (*str == 'E')
			set_text(set->t_e, str + 2);
		else if (*str == 'S' && *(str + 1) == 'O')
			set_text(set->t_s, str + 2);
		else if (*str == 'W')
			set_text(set->t_w, str + 2);
		else if (*str == 'S')
			set_text(set->t_sp, str + 1);
		else if (*str == 'F' || *str == 'C')
			set_text(set->t_n, str);
	}
	return (str);
}
