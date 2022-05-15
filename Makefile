NAME = push_swap

CC	=	cc

CFLAGS = -g -Wall -Wextra -Werror

SRCS = $(wildcard *.c)

LIBS = $(wildcard *.a)

OBJS = $(patsubst %.c, %.o, $(SRCS))

RM = rm -f

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

bonus:	all

.PHONY: all clean fclean re bonus
