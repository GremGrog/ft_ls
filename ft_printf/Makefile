NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

DIR_S = Srcs

DIR_O = obj

SRCF := HighestFunctions/*.c \
		HighestFunctions/Parsing/*.c \
		Char/*.c \
		String/*.c \
		Pointer/*.c \
		OxX/*.c \
		DI/*.c \
		Unsigned/*.c \
		Float/*.c

SRCS = $(addprefix $(DIR_S)/,$(SRCF))

OBJF = $(addprefix $(DIR_O)/,$(SRCF:.c=.o))

INCLUDE = MainHeader

all: $(NAME)

$(NAME): $(DIR_O) $(OBJF)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJF)
	ranlib $(NAME)

$(DIR_O):
	@mkdir -p obj
	@mkdir -p obj/HighestFunctions
	@mkdir -p obj/HighestFunctions/Parsing
	@mkdir -p obj/Char
	@mkdir -p obj/String
	@mkdir -p obj/Pointer
	@mkdir -p obj/OxX
	@mkdir -p obj/DI
	@mkdir -p obj/Unsigned
	@mkdir -p obj/Float

$(DIR_O)/%.o: $(DIR_S)/%.c
	@gcc $(FLAGS) -I $(INCLUDE) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJF)
	@/bin/rm -rf $(DIR_O)
	@make clean -C libft

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft

re: fclean all
