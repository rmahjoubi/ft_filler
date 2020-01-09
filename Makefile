# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 23:14:05 by rmahjoub          #+#    #+#              #
#    Updated: 2019/09/21 15:57:43 by rmahjoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rmahjoub.filler

SRC_PATH = srcs

SRC_NAME =	extrafun.c\
		getter.c\
		heatter.c\
		inis.c\
		placer.c\
		play.c\
		updatter.c

INC_PATH = -Iincludes -Ilibft/includes

LIB = -Llibft

LIB_NAME = -lft

OBJ_PATH = objs

OBJ_NAME = $(SRC_NAME:.c=.o)

FLAGS = gcc -Wall -Werror -Wextra

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: cmpile_libft $(NAME)

$(NAME): $(OBJ)
	$(FLAGS) $(LIB) $(LIB_NAME) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(FLAGS) $(INC_PATH) -o $@ -c $<

cmpile_libft:
	make -C libft
clean:
	@make -C libft clean
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make -C libft fclean
	rm -fv $(NAME)

re: fclean all
