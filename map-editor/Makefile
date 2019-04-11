# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/27 16:55:32 by ghalvors          #+#    #+#              #
#    Updated: 2019/04/11 16:06:34 by ghalvors         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = map-editor
GCC = gcc -Wall -Wextra -Werror -O0 -g
SRCDIR = srcs
OBJDIR = obj
SRCS := $(shell find $(SRCDIR) -type f -name '*.c')
OBJECTS := $(patsubst srcs/%,obj/%,$(SRCS:%.c=%.o))
INCLUDESDIR = includes
HEADER = $(shell find $(INCLUDESDIR) -type f -name '*.h')
LIB_INC = -L ../libft/ -lft -lm
SDL_LIBS = $(shell pkg-config --libs sdl2 SDL2_mixer SDL2_image)
PRINTF = test $(VERBOSE)$(TRAVIS) || printf

.PHONY: all

all:
	@$(PRINTF) "\r\033[0;36mCompiling map editor \n"
	@$(PRINTF) "%-20s\r\033[0;36m$(NAME)\033[0m"
	$(MAKE) -q $(NAME) ; \
	if [ $$? -eq 0 ] ; then $(PRINTF) "\r\x1b[20C\x1b[0K\033[0;31m $(NAME) \
	is already up to date\033[0m\n"; \
	else $(MAKE) $(NAME) && $(PRINTF) "\r\x1b[20C\x1b[0K\033[0;32m✔\033[0m\n"; \
	fi
	@$(PRINTF) "\r\033[0;35mProgram compiled succesfuly\n"


$(NAME): $(OBJECTS)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$@"
	$(GCC) -I $(INCLUDESDIR) $(LIB_INC) $(OBJECTS) $(SDL_LIBS) $(shell sdl2-config --cflags --libs) -o $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADER)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$@"
	$(GCC) $(shell sdl2-config --cflags) -I $(INCLUDESDIR) -I ../libft -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

ifndef VERBOSE
 ifndef TRAVIS
.SILENT:
 endif
endif
