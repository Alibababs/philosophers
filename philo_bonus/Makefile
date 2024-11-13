GREEN=\033[1;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET = \033[0m


NAME		=	philo_bonus

CC			=	cc

FLAG		=	-Wall -Wextra -Werror -g3 -I ./includes


LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

C_FILE		=	main	 		\
				state			\
				init			\
				utils			\
				dining			\
				log				\
				clear			\

SRC_DIR		=	./srcs/

SRC			=	$(addsuffix .c, $(addprefix $(SRC_DIR),$(C_FILE)))

OBJ			=	$(SRC:.c=.o)

.c.o:
	@$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)COMPILING $(NAME)...\n"
	@$(CC) $(OBJ) $(FLAG) -o $(NAME)
	@echo "$(GREEN)./$(NAME) created\n$(RESET)"

clean:
	@echo "$(RED)Deleting $(NAME) object...\n"
	@rm -f $(OBJ)
	@echo "$(GREEN)Done\n$(RESET)"

fclean: clean
	@echo "$(RED)Deleting $(NAME) executable...\n"
	@rm -f $(NAME)
	@echo "$(GREEN)Done\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re
