# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamsate <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 21:58:37 by shamsate          #+#    #+#              #
#    Updated: 2023/03/29 21:58:39 by shamsate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client

NAME_S = server

CC = cc

AR = ar rc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SRCS = $(src)/client.c \
		$(src)/server.c \
		$(src)/minitalk.dependency.c \

OBJS = (SRCS:.c=.o)

$(NAME_C) = $(OBJS)
			$(AR) $(NAME_C) $(OBJS)

$(NAME_S) = $(OBJS)
			$(AR) $(NAME_S) $(OBJS)

all : $(NAME_C) $(NAME_S)

%.o: %.c include/minitalk.h
		$(cc) $(CFLAGS) -c $< -o $@

clean :
		$(RM)$(OBJS)

fclean : clean
		$(RM) $(NAME_C) $(NAME_S)

re : fclean all

.PHONY : all clean fclean re
