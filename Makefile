##
## EPITECH PROJECT, 2017
## make
## File description:
## pool
##


CC	=	gcc -W -Wall -Wextra -I ./include

SRCS	=	./src/my_hunter.c	\
		./src/sprite.c		\
		./src/window.c		\
		./src/destroy.c		\
		./src/victory.c		\
		./src/my_put_nbr.c	\
		./src/help.c		\
		./src/my_strcmp.c	\
		./src/my_putstr.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	my_hunter

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC)  $(OBJS) -l c_graph_prog -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
