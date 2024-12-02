NAME = push_swap
FLAGS = -I -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIBFT_PRINTF = ./libft_printf/libftprintf.a

SRC_FILES = push_swap.c \
		./src/ps_assign_input.c \
		./src/ps_stack.c \
		./src/ps_utils.c \
		./src/ps_validate_input.c \
		./sort/sorting_algo.c \
		./sort/operations.c \
		./sort/smallsort_src.c

OBJ = $(SRC_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT_PRINTF) $(OBJ)
		gcc -o $(NAME) $(OBJ) $(LIBFT_PRINTF)


$(LIBFT_PRINTF):
		@echo "-------------------\n MAKE LIBFT_PRINTF    \n-------------------\n"
		@$(MAKE) -C./libft_printf

%.o:%.c
	gcc -c $(FLAGS) $< -o $@

clean:
	$(MAKE) clean -C./libft_printf
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIBFT_PRINTF)

re: fclean all

.PHONY: all clean fclean re
