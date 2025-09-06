NAME = pipex

SRC = pipex.c libft/libft.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	cc $(CFLAGS) $(SRC) -o $(NAME)
	
clean:
	rm -f $(NAME)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean flean re
