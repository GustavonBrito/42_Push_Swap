NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = main.c  \
       ps_fon1.c \
       ps_fon2.c \
       utils1.c \
       utils.c \
       checks.c\
       short_sort.c \
       radix.c \
       init.c 

OBJ_DIR = build
OBJS =	$(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: fclean re clean all