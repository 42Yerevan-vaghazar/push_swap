NAME = push_swap
BONUS = checker

CC	=	cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)

SRCS_BONUS = $(wildcard ./bonus/*.c)

SRCS_BONUS += $(filter-out main.c,$(SRCS))

LIBS = $(shell find . -name '*.a')

OBJS = $(patsubst %.c, %.o, $(SRCS))

OBJS_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS))

RM = rm -f

AR = ar rcs

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all:  $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	
$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make --no-print-directory -C $(FT_PRINTF_DIR)

bonus: $(OBJS_BONUS)
		$(CC) $(CFLAGS) $(LIBS) $(OBJS_BONUS) -o $(BONUS)
		
clean:
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@make --no-print-directory clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJS)
	$(RM) ./bonus/checker.o

fclean: clean
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@make --no-print-directory fclean -C $(FT_PRINTF_DIR)
	$(RM) $(NAME) $(BONUS)

re:	fclean all bonus

.PHONY: all clean fclean re bonus
