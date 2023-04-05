# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamsate <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 21:58:37 by shamsate          #+#    #+#              #
#    Updated: 2023/04/05 08:12:48 by shamsate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C=client
NAME_S=server

NAME_C_BONUS=client_bonus
NAME_S_BONUS=server_bonus


CC = cc

CFLAGS	= -Wall -Wextra -Werror

RM = rm -rf

SRCS_DIR = src/
INCLUDES_DIR = include/

SRC = $(addprefix $(SRCS_DIR), client.c server.c minitalk.dependency.c)

SRC_BONUS = $(addprefix $(SRCS_DIR), client_bonus.c server_bonus.c minitalk_utils.c)

OBJ = $(SRC:$(SRCS_DIR)%.c=$(SRCS_DIR)%.o)

OBJ_BONUS = $(SRC_BONUS:$(SRCS_DIR)%.c=$(SRCS_DIR)%.o)

all: $(NAME_C) $(NAME_S)

bonus: $(NAME_C_BONUS) $(NAME_S_BONUS)

$(NAME_C): $(SRCS_DIR)client.o $(SRCS_DIR)minitalk.dependency.o
	@$(CC) $(CFLAGS) $^ -o $@

$(NAME_S): $(SRCS_DIR)server.o $(SRCS_DIR)minitalk.dependency.o
	@$(CC) $(CFLAGS) $^ -o $@

$(NAME_C_BONUS): $(SRCS_DIR)client_bonus.o $(SRCS_DIR)minitalk.dependency.o
	@$(CC) $(CFLAGS) $^ -o $@

$(NAME_S_BONUS): $(SRCS_DIR)server_bonus.o $(SRCS_DIR)minitalk.dependency.o
	@$(CC) $(CFLAGS) $^ -o $@

$(SRCS_DIR)client.o: $(SRCS_DIR)client.c $(INCLUDES_DIR)minitalk.h
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -o $@ -c $<

$(SRCS_DIR)minitalk.dependency.o: $(SRCS_DIR)minitalk.dependency.c $(INCLUDES_DIR)minitalk.h
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -o $@ -c $<

$(SRCS_DIR)server.o: $(SRCS_DIR)server.c $(INCLUDES_DIR)minitalk.h
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -o $@ -c $<

$(SRCS_DIR)client_bonus.o: $(SRCS_DIR)client_bonus.c $(INCLUDES_DIR)minitalk_bonus.h
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -o $@ -c $<

$(SRCS_DIR)server_bonus.o: $(SRCS_DIR)server_bonus.c $(INCLUDES_DIR)minitalk_bonus.h
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -o $@ -c $<

clean:
	@$(RM) $(SRCS_DIR)*.o

fclean: clean
	@$(RM) $(NAME_C) $(NAME_S) $(NAME_C_BONUS) $(NAME_S_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
