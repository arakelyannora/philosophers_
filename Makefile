NAME= philo

HEADER= philosophers.h


CC= gcc
CFLAGS = -Wall -Werror -Wextra
THREAD = -pthread

SRCS = 	check_data.c \
		errors.c \
		init.c \
		main.c \
		simulation.c \
		utils.c \
		utils2.c \
		validations.c \

OBJS = $(SRCS:.c=.o)


all: $(NAME)
	
%.o: %.c $(HEADER) $(HEADER_BONUS)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(HEADER) 
	@$(CC) $(CFLAGS) $(THREAD) $(OBJS) -o $(NAME)


clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re