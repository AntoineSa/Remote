/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 11:19:36 by asablayr          #+#    #+#             */
/*   Updated: 2019/11/29 14:29:59 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int		pad;
	int		spa;
	int		size;
	int		prec;
	int		alt;
	char	conv;
	void	*arg;
}				t_flag;

typedef char	*(*t_aff)(t_flag);

int				ft_printf(const char *s, ...);
int				get_flags(const char *s, t_flag *flags);
void			check_alt(char *s, int *flag);
int				check_conv(char c, char *conv);
int				check_nb(char *c, int *flag);
int				check_padding(char *s, t_flag *flags);
int				check_perc(char *s, t_flag *flags);
void			get_arg(va_list aq, char c, t_flag *flags);
void			get_alt(char *s, t_flag *flags);
int				print(va_list aq, t_flag *flags, int prec);
char			*do_shit(va_list aq, t_flag *flags, char *str);
char			*format(char *str, t_flag flags);
char			*format_neg(char *str, t_flag flags);
char			*format_char(char *str, t_flag flags);
char			*alt_format(char *str, t_flag flag);
char			*print_str(t_flag flags);
char			*print_addr(t_flag flags);
char			*print_int(t_flag flags);
char			*print_unsigned_int(t_flag flags);
char			*print_hexa(t_flag flags);
char			*print_hexa_min(unsigned long nb);

int				ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *str, int c);
int				ft_atoi(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strfjoin(char *s1, char *s2);
char			*ft_strffjoin(char *s1, char *s2);
void			*ft_calloc(size_t count, size_t size);
void			ft_memset(void *b, int c, size_t len);

#endif
