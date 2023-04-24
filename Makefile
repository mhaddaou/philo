# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddaou <mhaddaou@student.1337.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 01:18:16 by mhaddaou          #+#    #+#              #
#    Updated: 2022/05/26 01:33:58 by mhaddaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




NAME = philo

HEADER = includes/philosopher.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = src/philo.c src/action.c src/check_info.c src/check_info2.c src/create_philo.c src/err_handl.c src/get_info.c src/init_all.c src/time.c src/utiles.c src/check_death.c\
	
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f src/*.o 

fclean: clean
	@rm -f philo

re: fclean all
