/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:26:41 by fclivaz           #+#    #+#             */
/*   Updated: 2023/01/19 15:26:43 by fclivaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "MLX/mlx.h"
# include "libft/libft/libft.h"
# include "keycodes.h"

typedef struct s_images
{
	void	*player;
	void	*walls;
	void	*coins;
	void	*exit;
	void	*foe;
	void	*bg;
}	t_images;

typedef struct s_playerdata
{
	int	pos_x;
	int	pos_y;
	int	score;
	int	lives;
	int	steps;

}	t_playerdata;

typedef struct s_mlxdata
{
	void			*pid;
	void			*wid;
	int				*wsize;
	char			**map;
	int				tscore;
	t_images		imgs;
	t_playerdata	pdata;
}	t_mlxdata;

// --- CHECKS --- //

void	check_valid_map(int argc, char **argv, void *g);
void	check_weird_signs(void *g);
void	map_validator(void *g);
void	free_map(char **map);
void	check_walls(void *g, char **map);
int		maplen(const char *s);
char	**copy_map(char **map);

// --- FLOOD FILL UTILS --- //

void	replace_char(char **map, char c);

// --- GAME LOGIC --- //

void	load_images(void *g);
void	populate_map(void *g);
int		close_game(void *g);

// --- PLAYER LOGIC --- //

void	player_interact(int key, void *g);
int		end_checks(void *g);

// --- BUNGIE SPECIFIC --- //

void	error_players(char **map, void *g, int mode);
void	error_walls(char **map, void *g, int mode);
void	error_exits(char **map, void *g, int mode);
void	error_score(void *g, int mode);
void	error_pre_map(int mode, char *tmp);
void	error_map(void *g, int y, int x, char c);

// --- BONUSES --- //

void	display_steps(void *g);
void	display_collectible(void *g);
void	print_map(char **map);

#endif