SRCS	= so_long.c handle_images.c map_checks.c populate_map.c map_validator.c validator_utils.c player_logic.c error_codes.c game_over.c bonus_01.c

OBJS	= ${SRCS:.c=.o}

OBJDIR	= objs

NAME	= so_long

CFLAGS	= -Wall -Werror -Wextra

CC = cc

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			mv *.o ./objs/
			cd libft && ${MAKE}
			cd MLX && ${MAKE}
			${CC} $(patsubst %.o, ${OBJDIR}/%.o, ${OBJS}) -o ${NAME} -Llibft -lft -lmlx -LMLX -framework OpenGL -framework AppKit

all:	${NAME}

run:	${NAME}
		-./${NAME} maps/eee.ber
		-./${NAME} maps/recktangle.ber
		-./${NAME} maps/SWEEP.ber
		-./${NAME} maps/nocollectible.ber
		-./${NAME} maps/noescape.ber
		-./${NAME} maps/noplayer.ber
		-./${NAME} maps/TME.ber
		-./${NAME} maps/TMP.ber
		-./${NAME} maps/unreachable.ber
		-./${NAME} maps/wallbtm.ber
		-./${NAME} maps/wallleft.ber
		-./${NAME} maps/wallright.ber
		-./${NAME} maps/walltop.ber
		-./${NAME} maps/carte.ber

debug:
		cd libft && ${MAKE}
		cd MLX && ${MAKE}
		gcc ${SRCS} -o ${NAME} -Llibft -lft -lmlx -LMLX -framework OpenGL -framework AppKit -fsanitize=address
		-./${NAME} maps/eee.ber
		-./${NAME} maps/recktangle.ber
		-./${NAME} maps/SWEEP.ber
		-./${NAME} maps/nocollectible.ber
		-./${NAME} maps/noescape.ber
		-./${NAME} maps/noplayer.ber
		-./${NAME} maps/TME.ber
		-./${NAME} maps/TMP.ber
		-./${NAME} maps/unreachable.ber
		-./${NAME} maps/wallbtm.ber
		-./${NAME} maps/wallleft.ber
		-./${NAME} maps/wallright.ber
		-./${NAME} maps/walltop.ber
		-./${NAME} maps/carte.ber

metal:
		cd libft && ${MAKE}
		cd MLX_metal && ${MAKE}
		mv MLX_metal/libmlx.dylib .
		gcc ${SRCS} -o ${NAME} -Llibft -lft libmlx.dylib -framework Metal -framework AppKit
		./${NAME} maps/carte.ber

leaks: ${NAME}
		leaks -atExit -- ./${NAME} maps/eee.ber
		leaks -atExit -- ./${NAME} maps/recktangle.ber
		leaks -atExit -- ./${NAME} maps/SWEEP.ber
		leaks -atExit -- ./${NAME} maps/nocollectible.ber
		leaks -atExit -- ./${NAME} maps/noescape.ber
		leaks -atExit -- ./${NAME} maps/noplayer.ber
		leaks -atExit -- ./${NAME} maps/TME.ber
		leaks -atExit -- ./${NAME} maps/TMP.ber
		leaks -atExit -- ./${NAME} maps/unreachable.ber
		leaks -atExit -- ./${NAME} maps/wallbtm.ber
		leaks -atExit -- ./${NAME} maps/wallleft.ber
		leaks -atExit -- ./${NAME} maps/wallright.ber
		leaks -atExit -- ./${NAME} maps/walltop.ber
		leaks -atExit -- ./${NAME} maps/carte.ber

clean:
		rm -f libmlx.dylib
		rm -f ${OBJS}
		cd libft && ${MAKE} clean
		cd MLX && ${MAKE} clean

fclean:	clean
		rm -f ${NAME}
		cd libft && ${MAKE} fclean

re:		fclean all

.PHONY:	all fclean clean re