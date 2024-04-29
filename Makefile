NAME = push_swap

SRC =fill_stack.c \
	 	push.c \
		push_swap.c \
		rev_rotate.c \
		rotate.c \
		sort_utils.c \
		stack_utils.c \
		swap.c 
OBJ = $(SRC:.c = .o)

CFLAGS = -Wall -Werror -Wextra

CC = cc

RM = rm -f

INCLUDE = push_swap.h Makefile

%.o:%.c	$(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
