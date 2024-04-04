##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## nothing to see here just a makefile
##

SRC	 =	mini_flags.c	\
		mini_real.c	\
		arr_flags.c	\
		my_putchar.c	\
		my_putnbr.c	\
		my_putstr.c	\

INCLUDES	=	-iquote../../include

CPPFLAGS	=	$(INCLUDES)

CFLAGS	=	-Wall -Wextra

OBJ =	$(SRC:.c=.o)

NAME	=	libmini.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) ../$(NAME)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
