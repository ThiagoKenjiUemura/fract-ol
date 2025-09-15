# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 13:50:32 by thiagouemur       #+#    #+#              #
#    Updated: 2025/09/15 18:22:33 by tkenji-u         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/main.c  src/utils.c src/events.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I ./include -I ./lib/minilibx-linux -I ./lib/libft
LIBS = -L ./lib/minilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./lib/minilibx-linux
	@make -C ./lib/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C ./lib/minilibx-linux clean
	@make -C ./lib/libft clean

fclean: clean
	rm -f $(NAME)
	@make -C ./lib/minilibx-linux fclean
	@make -C ./lib/libft fclean

re: fclean all

.PHONY: all clean fclean re