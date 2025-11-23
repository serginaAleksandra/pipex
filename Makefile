NAME = pipex

SRCS = main.c pipe_proc.c execution.c
OBJS = main.o pipe_proc.o execution.o

BONUS = bonus/main_bonus.c bonus/pipe_proc_bonus.c bonus/child_proc_bonus.c \
		bonus/execution_bonus.c
B_OBJS = bonus/main_bonus.o bonus/pipe_proc_bonus.o bonus/child_proc_bonus.o \
			bonus/execution_bonus.o

LIBFT_DIR = libft_printf
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_DIR)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus : $(B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJS) $(B_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
