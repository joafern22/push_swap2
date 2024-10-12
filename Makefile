CFLAGS = -Werror -Wextra -Wall

SRC = main.c push_swap.c rotate.c r_rotate.c edge_cases.c greedy.c calculate.c execute.c find_prepare.c is_duplicate.c ft_isdecimal.c ft_atoi.c

OBJ = $(SRC:.c=.o)

RM = rm -f 
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re
