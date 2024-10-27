NAME = libftprintf.a

SOURCES =				\
	ft_printf.c			\
	ft_printf_utils.c	\
	ft_printf_ptr.c		\
	ft_printf_hex.c 	\

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJECTS)
			$(AR) -r $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
		rm -f $(OBJECTS)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
