CC = cc

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libftprintf.a

HEADER = -I $(LIBFT_DIR)

NAME = push_swap

SRCS =	main.c

OBJS =	$(SRCS:%.c=$(OBJ_DIR)/%.o)

OBJ_DIR = build

CFLAGS = -Werror -Wall -Wextra

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean:
	@make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
