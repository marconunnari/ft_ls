NAME= ft_ls
GCC=gcc -Wall -Wextra -Werror
INCLUDES= -Iincludes -Ilibft/includes
LIBFT=libft/libft.a
LFT= -Llibft -lft
SRCS_FILES= main
SRCS = $(addprefix srcs/, $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C libft

$(OBJS): %.o: %.c
	$(GCC) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $@ $^ $(LFT)

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
