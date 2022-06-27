NAME = philo
NAME_BONUS = philo_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRCS =
BONUS_SRCS=
OBJS = $(SRCS:%.c=%.o)
INC_DIR		=	./includes

OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $
$(NAME): $(OBJS)
	$(CC) -o $@ $^

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) -o $@ $^

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re :
		make fclean
		make all