# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asablayr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 19:03:59 by asablayr          #+#    #+#              #
#    Updated: 2020/01/05 18:53:56 by asablayr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADER = cube.h

INCL_PATH = ./incl

NAME = Cub3D

FILES = get_input \
		set_settings \
		parse \
		print \
		raycast \
		cube

SRCS = $(addsuffix .c, $(FILES))
SRCDIR = srcs/

OBJS = $(addsuffix .o, $(FILES))
OBJDIR = objs/

all: $(NAME)

$(NAME) : $(addprefix $(OBJDIR), $(OBJS))
	$(CC) -o $(NAME) -llibft.a $(addprefix $(OBJDIR), $(OBJS))
	
$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(addprefix -I, $(INCL_PATH)) -c $^ -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
