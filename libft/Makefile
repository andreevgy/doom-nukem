# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 09:59:38 by dmorgil           #+#    #+#              #
#    Updated: 2019/03/28 16:43:55 by ghalvors         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCC = gcc -Wall -Wextra -Werror
SRCS := $(shell find . -type f -name '*.c')
OBJECTS = $(SRCS:.c=.o)
PRINTF=printf $(VERBOSE)$(TRAVIS)

all:
	@$(PRINTF) "%-20s\r\033[0;33m$(NAME)\033[0m"
	$(MAKE) -q $(NAME) ; \
	if [ $$? -eq 0 ] ; then $(PRINTF) "\r\x1b[20C\x1b[0K\033[0;31m $(NAME) \
	is already up to date\033[0m\n"; \
	else $(MAKE) $(NAME) && $(PRINTF) "\r\x1b[20C\x1b[0K\033[0;32m✔\033[0m\n"; \
	fi


$(NAME): $(OBJECTS)
	@$(PRINTF) "\r\x1b[20C\x1b[0K$@"
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o : %.c
	@$(PRINTF) "\r\x1b[20C\x1b[0K$<"
	$(GCC) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re

ifndef VERBOSE
 ifndef TRAVIS
.SILENT:
 endif
endif
