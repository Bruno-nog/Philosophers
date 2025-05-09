# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 19:01:38 by brunogue          #+#    #+#              #
#    Updated: 2025/05/09 19:50:29 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philO

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -pthread -g3
INCLUDES_DIR = includes
INCLUDES = -I$(INCLUDES_DIR)

SRCS = srcs/main.c srcs/utils.c srcs/threads.h
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@	

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
