# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 17:22:13 by fmacgyve          #+#    #+#              #
#    Updated: 2019/03/05 17:32:13 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= mapgen
FLAGS		= -Wall -Wextra -Werror
all: $(NAME)

$(NAME): generate_map.c
	make -C ../libft
	gcc $(FLAGS) generate_map.c ../libft/libft.a -I ../includes -o $(NAME)

clean:
	make clean -C ../libft
	rm -f $(RAW_OFILES)

fclean: clean
	make fclean -C ../libft
	rm -f *.wolf
	rm -rf $(NAME)

re: fclean all
