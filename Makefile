##
## EPITECH PROJECT, 2023
## make file
## File description:
## makes stuff
##

SRC	=	$(addprefix src/,\
		main.c	\
		to_test.c	\
		)

SRC_TEST	=	$(addprefix tests/,\
			redirect.c	\
			)

SRC_TO_TEST	=	$(filter-out src/main.c, $(SRC))

CPPFLAGS	=	-iquote./include

CFLAGS	+=	-Wall -Wextra

TEST_FLAGS	=	--coverage

LDFLAGS =	-L./libs

LDLIBS	=	-lmy -lmini -llink -larrays -lfree

TEST_LIBS	=	-lcriterion

CC	?=	gcc

OBJ	=	$(SRC:.c=.o)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

NAME	=	mysh

TEST_NAME	=	unit_tests

all:	build_libs $(NAME)

build_libs:
	make -C	libs/my
	make -C	libs/mini_print
	make -C	libs/linked_lists
	make -C	libs/arrays
	make -C	libs/freef

clean_libs:
	make clean -C libs/my
	make clean -C libs/mini_print
	make clean -C libs/linked_lists
	make clean -C libs/arrays

fclean_libs:
	make fclean -C libs/my
	make fclean -C libs/mini_print
	make fclean -C libs/linked_lists
	make fclean -C libs/arrays
	make fclean -C libs/freef

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean: clean_libs
	$(RM)  $(OBJ)

fclean:	clean fclean_libs
	$(RM) $(NAME)

re:	fclean all

debug: CFLAGS += -ggdb3
debug: re

asan: CC = clang -fsanitize=address
asan: re

$(TEST_NAME):	build_libs $(OBJ_TEST)
	$(CC) -o $(TEST_NAME) $(CFLAGS) $(CPPFLAGS)	\
	$(OBJ_TEST) $(SRC_TO_TEST) $(LDFLAGS) $(LDLIBS)	\
	-iquote./include -lcriterion --coverage	\

tests_run:	$(TEST_NAME)
	./$(TEST_NAME)

tests_clean:
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) coverage*
	$(RM) unit_tests

coverage:
	gcovr --html-details coverage && firefox coverage

.PHONY: all clean fclean re debug build_libs clean_libs fclean_libs \
	tests_run coverage tests_clean
