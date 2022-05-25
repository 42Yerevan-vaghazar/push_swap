NAME = push_swap
BONUS = checker

CC	=	cc

CFLAGS = -g -Wall -Wextra -Werror

SRCS = $(wildcard *.c)

SRCS_BONUS = $(wildcard ./bonus/*.c)

SRCS_BONUS += $(filter-out main.c, $(SRCS))

OBJS = $(patsubst %.c, %.o, $(SRCS))

OBJS_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS))

RM = rm -f

FT_PRINTF_DIR = ft_printff
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

LINKERS = -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

all:  $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKERS)
	
$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make --no-print-directory -C $(FT_PRINTF_DIR)

bonus:	$(BONUS)

$(BONUS): $(LIBFT) $(FT_PRINTF) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS) $(LINKERS)

clean:
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@make --no-print-directory clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJS_BONUS) $(OBJS)

fclean: clean
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@make --no-print-directory fclean -C $(FT_PRINTF_DIR)
	$(RM) $(NAME) $(BONUS)

re:	fclean all

.PHONY: all clean fclean re bonus