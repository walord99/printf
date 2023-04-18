CC			= 	gcc
SRC_NAME	= 	ft_printf3.c
SRC			=  	$(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJS		= 	$(addprefix $(BIN_DIR)/, $(SRC_NAME:.c=.o))
NAME		= 	libftprintf.a
CFLAGS		= 	-Wall -Wextra -Werror -Wno-unused-parameter
LIBC		= 	ar rcs
BIN_DIR		= 	bin
SRC_DIR		= 	src
HEAD_DIR	= 	headers
LIBFT_DIR	= 	libft

all : $(NAME)

$(NAME) : $(BIN_DIR) $(OBJS)
	make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	@mv libft.a $(NAME)
	$(LIBC) $@ $(OBJS) 

$(BIN_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -g $< -o $@ -I $(HEAD_DIR) -I $(LIBFT_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

debug: all test
	lldb a.out

test: all 
	gcc testmain.c libftprintf.a -I headers -I libft -g 
	./a.out

# gcc -c src/ft_printf.c -o ft_printf.o -I headers/ -I ../libft
# ar rcs libftprintf.a ft_printf.o  
# gcc testmain.c libftprintf.a -I headers
