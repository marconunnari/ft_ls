NAME= ft_ls
GCC=gcc -Wall -Wextra -Werror
INCLUDES= -Iincludes -Ilibft/includes
LIBFT=libft/libft.a
LFT= -Llibft -lft
DOBJS= objs
DSRCS= srcs

SRCS_FILES= main get_info parse_args ls ft_btree_cmp \
			get_dirfiles ft_btree_apply_infix_ls get_file ft_btreeadd_ls #new#

SRCS = $(addprefix $(DSRCS)/, $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(SRCS:$(DSRCS)/%.c=$(DOBJS)/%.o)

all: $(NAME)

$(DOBJS):
	mkdir -p $(DOBJS)

$(LIBFT):
	make -C libft

$(OBJS): $(DOBJS)/%.o: $(DSRCS)/%.c
	$(GCC) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(DOBJS) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFT)

clean:
	make clean -C libft
	rm -rf $(DOBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
