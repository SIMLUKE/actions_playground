##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## nothing to see here just a makefile
##

SRC	 =	is_num.c	\
		my_getnbr.c	\

INCLUDES	=	-iquote../../include

CPPFLAGS	=	$(INCLUDES)

CFLAGS	=	-Wall -Wextra

OBJ =	$(SRC:.c=.o)

NAME	=	libmy.a

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
