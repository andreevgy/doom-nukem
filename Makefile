# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 17:22:13 by fmacgyve          #+#    #+#              #
#    Updated: 2019/03/26 18:23:24 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= doom-nukem
FLAGS		= -Wall -Wextra -Werror -O0 -g

SRC_DIR		= ./srcs
OBJ_DIR		= ./obj
INCL_DIR	= ./includes

CFILES		= main.c doom.c get_next_line.c read_map.c validate_map.c ray.c hooks.c movement.c rotating.c read_textures.c floor_casting.c read_music.c threads.c sprites.c init_sprite.c small_blocks.c
OFILES		= $(CFILES:.c=.o)
HFILES		= get_next_line.h libft.h doom.h

RAW_CFILES	= $(addprefix $(SRC_DIR)/,$(CFILES))
RAW_OFILES	= $(addprefix $(OBJ_DIR)/,$(OFILES))
RAW_HFILES	= $(addprefix $(INCL_DIR)/,$(HFILES))
SDL_LIBS	= $(shell pkg-config --libs sdl2 SDL2_mixer SDL2_image)
INCLUDES	= -I $(INCL_DIR)

all: $(OBJ_DIR) $(NAME) $(RAW_HFILES)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(RAW_OFILES)
	make -C ./libft
	gcc $(FLAGS) $(INCLUDES) $(RAW_OFILES) $(SDL_LIBS) $(shell sdl2-config --cflags --libs) libft/libft.a -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(RAW_HFILES) Makefile
	gcc $(FLAGS) $(INCLUDES) $(shell sdl2-config --cflags) -c $< -o $@

clean:
	make clean -C ./libft
	rm -f $(RAW_OFILES)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
