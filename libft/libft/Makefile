SRCS	= $(wildcard *.c)

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CFLAGS	= -Wall -Werror -Wextra

CC = gcc

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ../${NAME} ${OBJS}

all:	${NAME}

clean:
		rm -f ${OBJS}

.PHONY: all fclean clean re
