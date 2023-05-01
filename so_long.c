/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:18:05 by fclivaz           #+#    #+#             */
/*   Updated: 2023/01/20 16:18:26 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	maplen(const char *s)
{
	int		x;

	x = 0;
	while (s[x] != 0)
		x++;
	if (s[x - 1] == '\n')
		x--;
	return (x);
}

static int	deal_key(int key, void *g)
{
	t_mlxdata	*data;

	data = (t_mlxdata *)g;
	if (key == K_ESC || key == K_Q)
	{
		close_game((void *)data);
		return (key);
	}
	else if (key == K_W || key == K_A || key == K_S || key == K_D)
		player_interact(key, (void *)data);
	else if (key == K_UP || key == K_LEFT || key == K_DOWN || key == K_RIGHT)
	{
		if (key == K_UP)
			key = K_W;
		else if (key == K_DOWN)
			key = K_S;
		else if (key == K_LEFT)
			key = K_A;
		else if (key == K_RIGHT)
			key = K_D;
		player_interact(key, (void *)data);
	}
	return (0);
}

static int	*calculate_window(char **map)
{
	int		i;
	int		*size;
	char	*tmp;

	i = -1;
	size = (int *)malloc(2 * sizeof(int));
	tmp = map[0];
	size[0] = (ft_strlen(tmp)) * 64;
	size[1] = 0;
	while (map[++i] != NULL)
		size[1]++;
	size[1] = size[1] * 64;
	return (size);
}

int	close_game(void *g)
{
	t_mlxdata	*data;

	data = (t_mlxdata *)g;
	ft_printf("Total steps: %d\n", data->pdata.steps);
	free(data->wsize);
	free_map(data->map);
	ft_printf("Destroying MLX windows... #RipBozo\n");
	mlx_clear_window(data->pid, data->wid);
	mlx_destroy_window(data->pid, data->wid);
	ft_printf("Quitting. So long, my friend!\n");
	exit (0);
}

int	main(int argc, char **argv)
{
	t_mlxdata	g;

	check_valid_map(argc, argv, (void *)&g);
	g.wsize = calculate_window(g.map);
	g.pid = mlx_init();
	g.wid = mlx_new_window(g.pid, g.wsize[0], g.wsize[1], "Zero Squad");
	load_images((void *)&g);
	populate_map((void *)&g);
	mlx_do_key_autorepeaton(g.pid);
	mlx_key_hook(g.wid, deal_key, (void *)&g);
	mlx_hook(g.wid, 17, 0, close_game, (void *)&g);
	mlx_loop(g.pid);
	return (0);
}
