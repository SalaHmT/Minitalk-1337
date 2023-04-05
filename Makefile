# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamsate <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 21:58:37 by shamsate          #+#    #+#              #
#    Updated: 2023/04/05 07:32:21 by shamsate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SER=server
NAME_CLI=client

NAME_SER_BONUS=server_bonus
NAME_CLI_BONUS=client_bonus

CC = cc

RM = rm -rf

CFLAGS	= -Wall -Wextra -Werror

SRCS_DIR = src/
INCLUDES_DIR = include/

SRCS = $(addprefix $(SRCS_DIR), client.c server.c minitalk.dependency.c)

SRCS_BONUS = $(addprefix $(SRCS_DIR), client_bonus.c server_bonus.c minitalk_utils.c)

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(SRCS_DIR)%.o)

OBJS_BONUS = $(SRCS_BONUS:$(SRCS_DIR)%.c=$(SRCS_DIR)%.o)

all: $(NAME_CLI) $(NAME_SER)

bonus: $(NAME_CLI_BONUS) $(NAME_SER_BONUS)

$(NAME_CLI): $(SRCS_DIR)client.o $(SRCS_DIR)minitalk.dependency.o
	@$(CC) $(CFLAGS) $^ -o $@

$(NAME_SER): $(SRCS_DIR)server.o $(SRCS_DIR)minitalk.dependency.o
	@$(CC) $(CFLAGS) $^ -o $@

$(NAME_CLI_BONUS): $(SRCS_DIR)client_bonus.o $(SRCS_DIR)minitalk.dependency.o
	@$(CC) $(CFLAGS) $^ -o $@

$(NAME_SER_BONUS): $(SRCS_DIR)server_bonus.o $(SRCS_DIR)minitalk.dependency.o
	@$(CC) $(CFLAGS) $^ -o $@

$(SRCS_DIR)client.o: $(SRCS_DIR)client.c $(INCLUDES_DIR)minitalk.h
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -o $@ -c $<

$(SRCS_DIR)minitalk_utils.o: $(SRCS_DIR)minitalk_utils.c $(INCLUDES_DIR)minitalk.h
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
	@$(RM) $(NAME_CLI) $(NAME_SER) $(NAME_CLI_BONUS) $(NAME_SER_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
