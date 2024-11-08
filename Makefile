NAME = libftprintf.a

SRC =	ft_printf.c \
		writestring.c \
		writenumber.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@cc -Wall -Wextra -Werror -c $(SRC)

clean:
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
