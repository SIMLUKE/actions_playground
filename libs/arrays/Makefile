##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## nothing to see here just a makefile
##

SRC	 =	file_handling.c	\
		counters.c	\
		arr_destructors.c	\
		arr_modifiers.c	\
		arr_creators.c	\
		checkers.c	\
		get_input.c	\
		my_strdup.c	\
		my_strcomp.c	\
		my_strcat.c	\
		my_strlen.c	\
		str_to_quotes.c	\
		my_struncomment.c	\

INCLUDES	=	-iquote../../include

CPPFLAGS	=	$(INCLUDES)

CFLAGS	=	-Wall -Wextra -g

OBJ =	$(SRC:.c=.o)

NAME	=	libarrays.a

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
