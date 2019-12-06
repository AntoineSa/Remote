/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 11:19:36 by asablayr          #+#    #+#             */
/*   Updated: 2019/12/05 17:13:55 by asablayr         ###   ########.fr       */
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

typedef int		(*t_aff)(t_flag);

int				ft_printf(const char *s, ...);
int				get_flags(const char *s, t_flag *flags);
void			check_alt(char *s, int *flag);
int				check_conv(char c, char *conv);
int				check_nb(char *c, int *flag);
int				check_padding(char *s, t_flag *flags);
int				check_perc(char *s, t_flag *flags);
void			get_alt(char *s, t_flag *flags);
int				print(va_list aq, t_flag *flags, int prec);
int				format(char *str, t_flag flags);
int				format_neg(char *str, t_flag flags);
int				format_char(char *str, t_flag flags);
int				alt_format(char *str, t_flag flag);
int				print_str(t_flag flags);
int				print_addr(t_flag flags);
int				print_int(t_flag flags);
int				print_unsigned_int(t_flag flags);
int				print_hexa(t_flag flags);
char			*print_hexa_min(unsigned long nb);

int				ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_subfstr(char *s, unsigned int start, size_t len);
char			*ft_strchr(const char *str, int c);
int				ft_atoi(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strffjoin(char *s1, char *s2);
char			*ft_strf1join(char *s1, char *s2);
char			*ft_strf2join(char *s1, char *s2);
void			*ft_calloc(size_t count, size_t size);
void			ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_merge(void *dst, size_t len, void *src, size_t l);

#endif
