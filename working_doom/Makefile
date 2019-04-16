# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkuphal <hkuphal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 17:57:15 by hkuphal           #+#    #+#              #
#    Updated: 2019/04/15 12:24:37 by hkuphal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem
GCC = gcc -Werror -Wall -Wextra
SRC = main.c
OBJ = $(SRC:.c=.o)
INC = -I../includes\
			-I/Users/hkuphal/.brew/Cellar/sdl2/2.0.9_1/include/SDL2\
			-I/Users/hkuphal/.brew/Cellar/sdl2_image/2.0.4/include/SDL2\
			-I/Users/hkuphal/.brew/Cellar/sdl2_mixer/2.0.4/include/SDL2
LIBS = -L../libft -L/Users/hkuphal/.brew/lib -lft -lm -lSDL2_mixer -lSDL2_image\
		-lSDL2

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../libft/
	$(GCC) -o $(NAME) $(OBJ) $(LIBS)

%.o : %.c working_doom.h
	$(GCC) -c $< $(INC)

clean:
	rm -f $(OBJ)
	make -C ../libft clean

fclean: clean
	rm -f $(NAME)
	make -C ../libft fclean

re: fclean all