/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:10:13 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/05 18:57:38 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

typedef	struct	s_player
{
	int	x_pos;
	int	y_pos;
	int x_dir;
	int	y_dir;
	int m_pos[2];
}				t_player;

typedef	struct	s_settings
{
	int		res_x;
	int		res_y;
	char	*t_n;
	char	*t_e;
	char	*t_s;
	char	*t_w;
	char	*t_sp;
	int		*c_f;
	int		*c_c;
	char	**map;
}				t_settings;

void	get_color(char obj, t_settings *set, char *str);
void	get_text(char *text, char *str);
void	get_res(int *res_x, int *res_y, char *str);
void	init_set(t_settings *set);
void	get_input(t_settings *set, int fd);

#endif
