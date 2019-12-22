/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:10:13 by asablayr          #+#    #+#             */
/*   Updated: 2019/12/22 16:56:55 by asablayr         ###   ########.fr       */
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
	char	t_n;
	char	t_e;
	char	t_s;
	char	t_w;
	char	t_sp;
	int		c_f[3];
	int		c_c[3];
	char	**map;
}				t_settings

char	*get_settings(t_settings *set, int fd);
void	get_map(t_settings *set, int fd, char *str);

int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	ft_strjoin(char *s1, char *s2);
char	ft_strf1join(char *s1, char *s2);
char	ft_strf2join(char *s1, char *s2);
char	ft_strffjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
int		get_next_line(int fd, char **line);

#endif
