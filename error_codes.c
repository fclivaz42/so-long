/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:32:09 by fclivaz           #+#    #+#             */
/*   Updated: 2023/01/30 20:32:20 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_players(char **map, void *g, int mode)
{
	t_mlxdata	*data;

	data = (t_mlxdata *)g;
	free_map(map);
	free_map(data->map);
	ft_printf("\033[1;33mError:\033[0m\n");
	if (mode == 1)
		ft_printf("\033[1;31mMore than 1 Player found.\033[0m\n");
	if (mode == 2)
		ft_printf("\033[1;31mNo players found!\033[0m\n");
	exit (1);
}

void	error_score(void *g, int mode)
{
	t_mlxdata	*data;

	data = (t_mlxdata *)g;
	free_map(data->map);
	ft_printf("\033[1;33mError:\033[0m\n");
	if (mode == 0)
		ft_printf("\033[1;31mThere must be at least 1 collectible.\033[0m\n");
	if (mode == 1)
		ft_printf("\033[1;31mAt least 1 collectible isn't reachable.\033[0m\n");
	exit (1);
}

void	error_walls(char **map, void *g, int mode)
{
	t_mlxdata	*data;

	data = (t_mlxdata *)g;
	free_map(map);
	free_map(data->map);
	ft_printf("\033[1;33mError:\033[0m\n");
	if (mode == 0)
		ft_printf("\033[1;31mTop wall has a hole.\033[0m\n");
	if (mode == 1)
		ft_printf("\033[1;31mLeft wall has a hole.\033[0m\n");
	if (mode == 2)
		ft_printf("\033[1;31mRight wall has a hole.\033[0m\n");
	if (mode == 3)
		ft_printf("\033[1;31mBottom wall has a hole.\033[0m\n");
	exit (1);
}

void	error_exits(char **map, void *g, int mode)
{
	t_mlxdata	*data;

	data = (t_mlxdata *)g;
	free_map(map);
	free_map(data->map);
	ft_printf("\033[1;33mError:\033[0m\n");
	if (mode == 0)
		ft_printf("\033[1;31mThere is no escape.\033[0m\n");
	if (mode == 1)
		ft_printf("\033[1;31mThere are too many exits.\033[0m\n");
	if (mode == 2)
		ft_printf("\033[1;31mExit is not reachable.\033[0m\n");
	exit (1);
}

void	error_map(void *g, int y, int x, char c)
{
	t_mlxdata	*data;

	data = (t_mlxdata *)g;
	ft_printf("\033[1;33mError:\033[0m\n");
	ft_printf("\033[1;31mWakanda wacky char '%c' is there at ", c);
	ft_printf("%d,%d?\033[0m\n", y, x);
	free_map(data->map);
	exit (1);
}
