NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

FT_PRINTF_DIR = libft/ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC = src/main.c src/stack.c src/erro.c src/verify_stack.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) bonus
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(FT_PRINTF_LIB)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all
