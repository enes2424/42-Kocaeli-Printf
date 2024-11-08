NAME = libftprintf.a
RM = rm -rf

SRC = 	ft_printf.c \
		writestring.c \
		writenumber.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@cc -Wall -Wextra -Werror -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
