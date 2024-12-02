NAME = libftprintf.a
FLAGS = -I -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIBFT = ./libft/libft.a

SRC_FILES = ft_printf.c \
			./src/ft_print_hexl.c \
			./src/ft_print_hexu.c \
			./src/ft_print_nb.c \
			./src/ft_print_ptr.c \
			./src/ft_print_putchar.c \
			./src/ft_print_putstr.c \
			./src/ft_print_unb.c \

OBJ = $(SRC_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@cp ./libft/libft.a $(NAME)
		$(AR) $(NAME) $(OBJ)
		
$(LIBFT):
		@echo "-------------------\n MAKE LIBFT       \n-------------------\n"
		@$(MAKE) -C./libft

%.o:%.c
		gcc -c $(FLAGS) $< -o $@
		

clean:
		$(MAKE) clean -C./libft
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re
