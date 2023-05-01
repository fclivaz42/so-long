/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:09:23 by fclivaz           #+#    #+#             */
/*   Updated: 2023/02/02 19:09:25 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(void *g, char **map)
{
	t_mlxdata	*data;
	int			x;
	int			y;

	data = (t_mlxdata *)g;
	x = -1;
	y = -1;
	while (map[0][++x] != 0)
	{
		if (map[0][x] != '1')
			error_walls(map, (void *)data, 0);
	}
	x = -1;
	while (map[++y] != NULL)
	{
		if (map [y][0] != '1')
			error_walls(map, (void *)data, 1);
		if (map [y][ft_strlen(map[0]) - 1] != '1')
			error_walls(map, (void *)data, 2);
	}
	while (map[y - 1][++x] != 0)
	{
		if (map[y - 1][x] != '1')
			error_walls(map, (void *)data, 3);
	}
}

void	replace_char(char **map, char c)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != 0)
		{
			if (map[y][x] == c)
				map[y][x] = '0';
		}
	}
}

void	check_weird_signs(void *g)
{
	t_mlxdata	*data;
	char		**map;
	int			x;
	int			y;

	data = (t_mlxdata *)g;
	map = data->map;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != 0)
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'P')
			{
				if (map[y][x] != 'E' && map[y][x] != 'C' && map[y][x] != 'F')
					error_map((void *)data, y, x, map[y][x]);
			}
		}
	}
}
