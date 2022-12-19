# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atouba <atouba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 22:42:24 by atouba            #+#    #+#              #
#    Updated: 2022/12/19 19:02:44 by atouba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc -I /usr/local/include -g

FILES = sources/main.c sources/play.c	sources/move.c sources/move_utils.c sources/ft_put.c	\
		sources/move_utils_two.c																			\
		map_stuff/check_map.c map_stuff/parse_map.c map_stuff/check_functions.c					\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 							\
		images/images_to_map.c images/init_images.c

FLAG = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

sanit = -fsanitize=address

$(NAME):
	$(CC) $(FLAG) $(FILES) -o $(NAME)

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf so_long

re: fclean all
