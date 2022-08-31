# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 20:45:07 by gbelange          #+#    #+#              #
#    Updated: 2022/08/08 19:23:20 by jmorneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

				
NAME = push_swap.a
LIBFT = libft.a
CC = @gcc
CFLAGS = -Wall -Wextra -Werror
RM = @rm -f
OBJS = $(SRC_FILES:.c=.o)

SRC_DIR = src/

SRC_FILES =	./src/push_swap.c ./src/sort_arrays.c ./src/push_swap_utiles.c ./src/error_arguements.c \
			./src/Action_a.c ./src/Action_b.c ./src/push_swap_utiles2.c ./src/sort100.c \
			

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	gcc $(CFLAGS) push_swap.a
	mv a.out push_swap

clean:
	@$(RM) src/*.o

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)
	rm ./push_swap

make f :
		gcc -Warrior -Wall -Werror push_swap.a
	
re: fclean all