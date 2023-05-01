/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:37:48 by fclivaz           #+#    #+#             */
/*   Updated: 2023/01/27 17:37:57 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_checks(void *g)
{
	t_mlxdata	*data;

	data = (t_mlxdata *)g;
	if (data->pdata.score != data->tscore)
	{
		ft_printf("Missing Shadow Crystals! Get them all and come back.\n");
		return (0);
	}
	ft_printf("Bravo, got them all! Now let's get outta here\n");
	return (1);
}

void	error_pre_map(int mode, char *tmp)
{
	ft_printf("\033[1;33mError:\033[0m\n");
	if (mode == 0)
		ft_printf("\033[1;31mMap is empty!\033[0m\n");
	if (mode == 1)
	{
		ft_printf("\033[1;31mMap is not rectangular. Abort.\033[0m\n");
		free(tmp);
	}
	exit (1);
}
