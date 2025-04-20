NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libftprintf.a

HEADER = -I $(LIBFT_DIR)

SRCS = main.c  \
       operations.c \
       sort_algorithms.c \
       utils1.c \
       utils.c \
       init_validation.c\
       short_sort.c \
       radix.c \
       init.c 

OBJ_DIR = build

OBJS =	$(SRCS:%.c=$(OBJ_DIR)/%.o)

OBJS_LIBS = $(LIBFT_DIR)/%.o

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	@$(RM) $(OBJS) $(OBJS_LIBS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: fclean re clean all