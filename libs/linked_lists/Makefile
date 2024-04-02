##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## nothing to see here just a makefile
##

SRC	 =	delete.c	\
		insert.c	\
		print_list.c	\
		search.c	\
		sort.c	\

INCLUDES	=	-iquote../../include

CPPFLAGS	=	$(INCLUDES)

CFLAGS	=	-Wall -Wextra -g3

OBJ =	$(SRC:.c=.o)

NAME	=	liblink.a

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
