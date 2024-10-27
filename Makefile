NAME 			= libftprintf.a
LIBFT_PATH 		= LIBFT-42
LIBFT 			= $(LIBFT_PATH)/libft.a

SOURCES =				\
	ft_printf.c			\
	ft_printf_utils.c	\
	ft_printf_ptr.c		\
	ft_printf_hex.c 	\

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_PATH)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJECTS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) -rs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
