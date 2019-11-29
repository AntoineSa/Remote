/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:02:23 by asablayr          #+#    #+#             */
/*   Updated: 2019/11/06 17:52:27 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	100
# endif

typedef struct		s_list
{
	char			*s;
	int				fd;
	struct s_list	*next;
}					t_list;

char				*ft_strchr(char *s, int c);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char *s, int start, int len);
int					ft_strlen(char *str);
int					get_next_line(int fd, char **line);
t_list				*lst_new(int fd);
void				lst_add_back(t_list **head, t_list *n);

#endif
