/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:51:29 by fclivaz           #+#    #+#             */
/*   Updated: 2023/01/26 17:51:37 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_player(void *g, int x, int y)
{
	t_mlxdata	*data;
	void		*pid;
	void		*wid;

	data = (t_mlxdata *)g;
	pid = data->pid;
	wid = data->wid;
	data->pdata.pos_x = x;
	data->pdata.pos_y = y;
	data->map[y][x] = '0';
	data->pdata.steps = 0;
	data->pdata.score = 0;
	data->pdata.lives = 3;
	mlx_put_image_to_window(pid, wid, data->imgs.player, x * 64, y * 64);
	ft_printf("Player has been positionned on tile %d,%d!\n", y, x);
}

static void	place_tile(void *g, int x, int y, char type)
{
	t_mlxdata	*data;
	void		*pid;
	void		*wid;

	data = (t_mlxdata *)g;
	pid = data->pid;
	wid = data->wid;
	mlx_put_image_to_window(pid, wid, data->imgs.bg, x * 64, y * 64);
	if (type == '1')
		mlx_put_image_to_window(pid, wid, data->imgs.walls, x * 64, y * 64);
	else if (type == 'C')
		mlx_put_image_to_window(pid, wid, data->imgs.coins, x * 64, y * 64);
	else if (type == 'E')
		mlx_put_image_to_window(pid, wid, data->imgs.exit, x * 64, y * 64);
	else if (type == 'F')
		mlx_put_image_to_window(pid, wid, data->imgs.foe, x * 64, y * 64);
	else if (type == 'P')
		initialize_player((void *)data, x, y);
}

char	**copy_map(char **map)
{
	char	**copy;
	char	*tmp;
	int		y;

	y = 0;
	while (map[y] != NULL)
		y++;
	copy = (char **)ft_calloc(y + 1, sizeof(char *));
	y = 0;
	while (map[y] != NULL)
	{
		tmp = ft_strdup(map[y]);
		copy[y] = tmp;
		y++;
	}
	return (copy);
}

void	free_map(char **map)
{
	int	y;

	y = -1;
	while (map[++y] != NULL)
		free(map[y]);
	free(map);
}

void	populate_map(void *g)
{
	t_mlxdata	*data;
	char		*line;
	int			x;
	int			y;

	y = 0;
	data = (t_mlxdata *)g;
	while (data->map[y] != NULL)
	{
		line = data->map[y];
		x = 0;
		while (line[x] != 0)
		{
			place_tile((void *)data, x, y, line[x]);
			x++;
		}
		y++;
	}
}
