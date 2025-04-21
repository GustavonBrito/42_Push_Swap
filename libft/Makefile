CC			= cc
NAME		= libftprintf.a
HEADER		= ./
OBJ_DIR		= build

CFLAGS		= -Wall -Wextra -Werror $(foreach dir, $(HEADER), -I$(dir))

LIBFT_SRCS = \
	ft_atoi.c ft_toupper.c ft_tolower.c ft_isascii.c ft_isdigit.c ft_strncmp.c \
	ft_isalpha.c ft_isalnum.c ft_isprint.c ft_strlcpy.c ft_strrchr.c ft_strchr.c \
	ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_strlen.c ft_strlcat.c \
	ft_strnstr.c ft_calloc.c ft_bzero.c ft_memcpy.c ft_substr.c ft_strjoin.c \
	ft_strdup.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_atoi_hex.c \
	ft_printf/ft_putchar_fd_printf.c ft_printf/ft_putnbr_printf.c \
	ft_printf/ft_putptr_fd_printf.c ft_printf/ft_putstr_fd_printf.c \
	ft_printf/ft_to_hex_printf.c ft_printf/ft_unsigned_printf.c

PRINTF_SRCS = ft_printf/ft_printf.c
GNL_SRC = gnl/get_next_line.c gnl/get_next_line_utils.c

SRCS = $(LIBFT_SRCS) $(PRINTF_SRCS) $(GNL_SRC)
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ------------------------ REGRAS ------------------------

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@) # Cria o subdiretório necessário
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all