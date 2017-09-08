# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfuster <jfuster@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 12:31:26 by jfuster           #+#    #+#              #
#    Updated: 2017/08/16 12:32:09 by jfuster          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HOSTTYPE ?= $(shell uname -m)_$(shell uname -s)

NAME = libft_malloc_$(HOSTTYPE).so

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_PATH = srcs/

SRCS_NAME = block.c \
			free.c \
			malloc.c \
			page.c \
			realloc.c \
			root.c \
			search.c \
			show_mem.c \
			size.c \
			tools.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

all: odir $(NAME)

$(NAME): $(OBJS)
	@echo " - Making $(NAME)"
	@$(CC) -shared $(CFLAGS) -o $(NAME) $^ $(LIBRARY)
	@ln -sf $(NAME) libft_malloc.so

odir:
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -fPIC -o $@ -c $<

clean:
	@echo " - Cleaning objs"
	@rm -f $(OBJS)

fclean: clean
	@echo " - Cleaning executable"
	@rm -f $(NAME)
	@rm -f libft_malloc.so

re: fclean all

.PHONY: clean fclean re odir