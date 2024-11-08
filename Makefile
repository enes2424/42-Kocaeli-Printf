NAME = libftprintf.a
RM = rm -rf

SRC = 	ft_printf.c \
		writestring.c \
		writenumber.c

OBJ = *.o

all: $(NAME)

$(NAME):
	@cc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
