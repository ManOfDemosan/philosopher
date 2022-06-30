NAME 		=	philo

CC 			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRCS	 =	main.c \
			init_arg.c\
			util.c

OBJS = $(SRCS:%.c=%.o)

OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)
INCLUDES 	= 	-I./

.PHONY: all clean fclean re bonus

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) -o $@ $^

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re :
		make fclean
		make all