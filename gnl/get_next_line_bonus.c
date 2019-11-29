/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:02:03 by asablayr          #+#    #+#             */
/*   Updated: 2019/11/07 11:18:16 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

static int	get_line(int fd, char **left, char **line)
{
	int		ret;
	char	buff[BUFFER_SIZE + 1];
	char	*end_line;

	ret = 1;
	while ((ret = read(fd, buff, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (!(*left = ft_strjoin(*left, buff)))
			return (-1);
		if ((end_line = ft_strchr(*left, '\n')))
		{
			if (!(*line = ft_substr(*left, 0, (end_line - *left))) ||
				!(*left = ft_substr(*left, (end_line - *left) + 1, ret)))
				return (-1);
			return (1);
		}
	}
	*line = *left;
	*left = NULL;
	return (0);
}

t_list		*get_fd(t_list *lst, int fd)
{
	while (lst)
	{
		if (fd == lst->fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void		lst_add_back(t_list **head, t_list *new)
{
	t_list	*cur;

	if (!new || !head)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

int			get_next_line(int fd, char **line)
{
	static t_list	*head = NULL;
	t_list			*left;
	int				ret;
	char			*end;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(left = get_fd(head, fd)))
	{
		if (!(left = lst_new(fd)))
			return (-1);
		lst_add_back(&head, left);
	}
	if ((end = ft_strchr(left->s, '\n')))
	{
		if (!(*line = ft_substr(left->s, 0, (end - left->s))) ||
			!(left->s = ft_substr(left->s, (end - left->s) + 1, BUFFER_SIZE)))
			return (-1);
		return (1);
	}
	if ((ret = get_line(fd, &left->s, line)))
		return (ret == 1 ? 1 : -1);
	return (0);
}
