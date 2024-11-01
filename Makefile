NAME = libftprintf.a
RM = rm -rf
CC = gcc
FLAG = -Wall -Wextra -Werror
CMPL = $(CC) $(FLAG)

SRC = 	ft_printf.c \
		writestring.c \
		writenumber.c

OBJ = *.o

all: $(NAME)

$(NAME):
	@$(CMPL) -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
