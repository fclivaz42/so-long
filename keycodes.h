/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:19:46 by fclivaz           #+#    #+#             */
/*   Updated: 2023/01/20 16:19:51 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# ifdef __gnu_linux__
#  define K_ESC 65307
#  define K_UP 65362
#  define K_DOWN 65364
#  define K_LEFT 65361
#  define K_RIGHT 65363
#  define K_W 119
#  define K_S 115
#  define K_A 97
#  define K_D 100
#  define K_P 112
#  define K_MINUS 45
#  define K_PLUS 113
#  define K_R 114
#  define K_U 117
#  define K_J 106
#  define K_I 105
#  define K_K 107
#  define K_O 111
#  define K_L 108
# elif __APPLE__
#  define K_ESC 53
#  define K_UP 126
#  define K_DOWN 125
#  define K_LEFT 123
#  define K_RIGHT 124
#  define K_Q 12
#  define K_W 13
#  define K_S 1
#  define K_A 0
#  define K_D 2
#  define K_P 35
#  define K_MINUS 27
#  define K_PLUS 24
#  define K_R 15
#  define K_U 32
#  define K_J 38
#  define K_I 34
#  define K_K 40
#  define K_O 31
#  define K_L 37
# endif

#endif //KEYCODES_H
