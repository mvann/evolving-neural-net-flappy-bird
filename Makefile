# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvann <mvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 13:51:07 by mvann             #+#    #+#              #
#    Updated: 2018/01/12 17:04:07 by mvann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = neuroBird
COMP_FLAGS = -Wall -Wextra -Werror -g -O0
LIBFT = -L libft/ -lft
MINILIBX_DIR = minilibx_macos/
MINILIBX = -L $(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit
SRC = main.c\
events.c\
draw.c\
collision.c\
move.c\
calculations.c\
breeding.c\
destroy.c

all: $(NAME)

$(NAME):
	@cd libft/ && make
	@cd minilibx_macos/ && make
	@gcc $(COMP_FLAGS) -o $(NAME) $(SRC) $(LIBFT) $(MINILIBX)

test:
	@rm -f $(SRC:.c=.o)
	@rm -f $(NAME)
	@gcc $(COMP_FLAGS) -o $(NAME) $(SRC) $(LIBFT) $(MINILIBX)

clean:
	@rm -f $(SRC:.c=.o)
	@cd libft/ && make clean
	@cd $(MINILIBX_DIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft/ && make fclean

re: fclean all
