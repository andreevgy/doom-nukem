# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 17:22:13 by fmacgyve          #+#    #+#              #
#    Updated: 2019/03/12 12:50:07 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= doom-nukem
FLAGS		= -Wall -Wextra -Werror -O0 -g
LIBS		= -I ./libs/SDL2_image.framework/Versions/A/Headers -I ./libs/SDL2_mixer.framework/Versions/A/Headers -I ./libs/SDL2.framework/Versions/A/Headers -I ./includes
FRAMEWORKS	= -F ./libs/ -framework SDL2 -F ./libs/ -framework SDL2_image -F ./libs/ -framework SDL2_mixer

SRC_DIR		= ./srcs
OBJ_DIR		= ./obj
INCL_DIR	= ./includes

CFILES		= main.c doom.c get_next_line.c read_map.c validate_map.c ray.c hooks.c movement.c rotating.c read_textures.c floor_casting.c read_music.c threads.c
OFILES		= $(CFILES:.c=.o)
HFILES		= get_next_line.h libft.h doom.h

RAW_CFILES	= $(addprefix $(SRC_DIR)/,$(CFILES))
RAW_OFILES	= $(addprefix $(OBJ_DIR)/,$(OFILES))
RAW_HFILES	= $(addprefix $(INCL_DIR)/,$(HFILES))

all: $(OBJ_DIR) $(NAME) $(RAW_HFILES)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(RAW_OFILES)
	make -C ./libft
	gcc $(FLAGS) $(LIBS) $(FRAMEWORKS) $(RAW_OFILES) libft/libft.a -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(RAW_HFILES)
	gcc $(FLAGS) $(LIBS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -f $(RAW_OFILES)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
