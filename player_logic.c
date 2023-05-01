/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:16:14 by fclivaz           #+#    #+#             */
/*   Updated: 2023/01/24 17:16:25 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_sprite(int x, int y, void *g)
{
	t_mlxdata	*data;
	int			plrx;
	int			plry;
	void		*plr;
	void		*bg;

	data = (t_mlxdata *)g;
	plr = data->imgs.player;
	bg = data->imgs.bg;
	plrx = data->pdata.pos_x * 64;
	plry = data->pdata.pos_y * 64;
	mlx_put_image_to_window(data->pid, data->wid, bg, plrx, plry);
	mlx_put_image_to_window(data->pid, data->wid, plr, plrx, plry);
	mlx_put_image_to_window(data->pid, data->wid, bg, plrx + x, plry + y);
}

static void	move_player(int key, void *g)
{
	t_mlxdata	*data;

	data = (t_mlxdata *)g;
	if (key == K_W)
	{
		data->pdata.pos_y = data->pdata.pos_y - 1;
		update_sprite(0, 64, (void *)data);
	}
	else if (key == K_S)
	{
		data->pdata.pos_y = data->pdata.pos_y + 1;
		update_sprite(0, -64, (void *)data);
	}
	else if (key == K_A)
	{
		data->pdata.pos_x = data->pdata.pos_x - 1;
		update_sprite(64, 0, (void *)data);
	}
	else if (key == K_D)
	{
		data->pdata.pos_x = data->pdata.pos_x + 1;
		update_sprite(-64, 0, (void *)data);
	}
	data->pdata.steps = data->pdata.steps + 1;
	display_steps((void *)data);
}

static int	check_tile(int key, void *g, char check)
{
	t_mlxdata	*data;

	data = (t_mlxdata *)g;
	if (key == K_W)
	{
		if (data->map[data->pdata.pos_y - 1][data->pdata.pos_x] == check)
			return (1);
	}
	else if (key == K_S)
	{
		if (data->map[data->pdata.pos_y + 1][data->pdata.pos_x] == check)
			return (1);
	}
	else if (key == K_D)
	{
		if (data->map[data->pdata.pos_y][data->pdata.pos_x + 1] == check)
			return (1);
	}
	else if (key == K_A)
	{
		if (data->map[data->pdata.pos_y][data->pdata.pos_x - 1] == check)
			return (1);
	}
	return (0);
}

static void	collect_item(int key, void *g)
{
	t_mlxdata	*data;

	data = (t_mlxdata *)g;
	if (key == K_W)
	{
		data->map[data->pdata.pos_y - 1][data->pdata.pos_x] = '0';
	}
	else if (key == K_S)
	{
		data->map[data->pdata.pos_y + 1][data->pdata.pos_x] = '0';
	}
	else if (key == K_D)
	{
		data->map[data->pdata.pos_y][data->pdata.pos_x + 1] = '0';
	}
	else if (key == K_A)
	{
		data->map[data->pdata.pos_y][data->pdata.pos_x - 1] = '0';
	}
	data->pdata.score = data->pdata.score + 1;
	display_collectible((void *)data);
}

void	player_interact(int key, void *g)
{
	t_mlxdata	*data;
	int			x;

	x = 0;
	data = (t_mlxdata *)g;
	if (check_tile(key, (void *)data, 'C'))
		collect_item(key, (void *)data);
	if (check_tile(key, (void *)data, 'E'))
	{
		if (end_checks((void *)data))
		{
			move_player(key, (void *)data);
			close_game((void *)data);
		}
	}
	if (check_tile(key, (void *)data, '0'))
		move_player(key, (void *)data);
}

void	print_map(char **map)
{
	int y;

	y = -1;
	ft_printf("------------------\n");
	while (map[++y] != NULL)
		ft_printf("%s\n", map[y]);
	ft_printf("------------------\n");
}