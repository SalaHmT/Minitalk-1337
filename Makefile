NAME_C = client

NAME_S = server



CC = cc

AR = ar rc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SRC = src

SRCS = $(src)/client.c \
       $(src)/server.c \
       $(src)/minitalk_dependency.c \
       
OBJS = (SRCS:.c=.o)

$(NAME_C):$(OBJ)
		$(AR) $(NAME_C) $(OBJ)
    
$(NAME_S):$(OBJ)
		$(AR) $(NAME_S) $(OBJ)
    
all:	$(NAME_C)$(NAME_S)

%.o: %.c include/minitalk.h
		$(CC) $(CFLAGS)  -c  $< -o $@
    
clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
