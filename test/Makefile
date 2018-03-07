NAME = libftprintf.a

SRC = ft_put.c ft_is_point.c hexidecimal.c other_chars.c\
      ft_is.c  width.c octal.c ft_is_num.c\
	    main.c ft_itoi_base.c unicode.c flags.c ft_is_cont.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<