/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:18:40 by fclivaz           #+#    #+#             */
/*   Updated: 2023/01/26 20:18:48 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_fill_nearby(char **map, int y, int x, char tile)
{
	int			amount;

	amount = 0;
	if (map[y - 1][x] == tile)
	{
		map[y - 1][x] = 'T';
		amount++;
	}
	if (map[y + 1][x] == tile)
	{
		map[y + 1][x] = 'T';
		amount++;
	}
	if (map[y][x - 1] == tile)
	{
		map[y][x - 1] = 'T';
		amount++;
	}
	if (map[y][x + 1] == tile)
	{
		map[y][x + 1] = 'T';
		amount++;
	}
	return (amount);
}

static int	fill_tool(char **map, char tile)
{
	int			score;
	int			filled;
	int			x;
	int			y;

	score = 0;
	filled = 1;
	while (filled != 0)
	{
		filled = 0;
		y = -1;
		while (map[++y] != NULL)
		{
			x = -1;
			while (map[y][++x] != 0)
			{
				if (map[y][x] == 'T')
				{
					filled = filled + check_fill_nearby(map, y, x, '0');
					score = score + check_fill_nearby(map, y, x, tile);
				}
			}
		//			ft_printf("changed %d tiles\n", filled);
		}
	//	print_map(map);
	}
	return (score);
}

static void	find_player(char **map, void *g)
{
	t_mlxdata	*data;
	int			found;
	int			x;
	int			y;

	data = (t_mlxdata *)g;
	y = -1;
	found = 0;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != 0)
		{
			if (map[y][x] == 'P' && found == 1)
				error_players(map, data, 1);
			else if (map[y][x] == 'P')
			{
				map[y][x] = 'T';
				found = 1;
			}
		}
	}
	if (found == 0)
		error_players(map, data, 2);
}

static void	count_score(void *g)
{
	t_mlxdata	*data;
	char		**map;
	int			score;
	int			x;
	int			y;

	data = (t_mlxdata *)g;
	map = data->map;
	y = 0;
	score = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != 0)
		{
			if (map[y][x] == 'C')
				score++;
			x++;
		}	
	y++;
	}
	if (score == 0)
		error_score(data, 0);
	data->tscore = score;
}

void	map_validator(void *g)
{
	t_mlxdata	*data;
	char		**maptest;
	int			score;

	data = (t_mlxdata *)g;
	check_weird_signs((void *)data);
	count_score((void *)data);
	score = 0;
	maptest = copy_map(data->map);
	find_player(maptest, (void *)data);
	check_walls((void *)data, maptest);
//
	score = fill_tool(maptest, 'C');
	if (score != data->tscore)
		error_score((void *)data, 1);
	free_map(maptest);
	maptest = copy_map(data->map);
	find_player(maptest, (void *)data);
	replace_char(maptest, 'C');
	score = fill_tool(maptest, 'E');
	if (score < 1)
		error_exits(maptest, (void *)data, 0);
	if (score > 1)
		error_exits(maptest, (void *)data, 1);
	free_map(maptest);
}
