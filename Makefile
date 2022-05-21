NAME = push_swap

CC	=	cc

CFLAGS = -g -Wall -Wextra -Werror

SRCS = $(wildcard *.c)

LIBS = $(shell find . -name '*.a')

OBJS = $(patsubst %.c, %.o, $(SRCS))

RM = rm -f

AR = ar rcs

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all:  $(NAME)


$(NAME) : $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	
$(LIBFT): 
	@make --no-print-directory -C $(LIBFT_DIR)

$(FT_PRINTF) : 
	@make --no-print-directory -C $(FT_PRINTF_DIR)

clean:
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@make --no-print-directory clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@make --no-print-directory fclean -C $(FT_PRINTF_DIR)
	$(RM) $(NAME)

re:	fclean all

bonus:	all

.PHONY: all clean fclean re bonus
