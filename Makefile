NAME=ft_ls
GCCF=-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	touch $(NAME)

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
