NAME	= libft.a

SUBDIR	= libft

${NAME}:
		cp ./SubMakefile ${SUBDIR}/Makefile
		cd ${SUBDIR} && ${MAKE} all

all:	${NAME}

clean:
		cd ${SUBDIR} && ${MAKE} clean

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY: all fclean clean re
