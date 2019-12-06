# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asablayr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 13:59:30 by asablayr          #+#    #+#              #
#    Updated: 2019/12/06 15:42:15 by asablayr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

HEADER = ft_printf.h

INCL_PATH = ./incl

NAME = libftprintf.a

FILES =	ft_atoi \
		ft_calloc \
		ft_memset \
		ft_memcpy \
		ft_printf \
		ft_strchr \
		ft_strjoin \
		ft_strlen \
		ft_substr \
		funct \
		parse \
		parse_funct \
		print \
		print_int \
		print_hexa \
		print_unsigned

SRCS	=	$(addsuffix .c, $(FILES))
SRCDIR	=	srcs/

OBJS	=	$(addsuffix .o, $(FILES))
OBJDIR	=	objs/

all: $(NAME)

$(NAME) : $(addprefix $(OBJDIR), $(OBJS))
	@ar -rcs $(NAME) $(addprefix $(OBJDIR), $(OBJS))

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CLFAGS) $(addprefix -I, $(INCL_PATH)) -c $^ -o $@

bonus: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
