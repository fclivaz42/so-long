/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:32:20 by fclivaz           #+#    #+#             */
/*   Updated: 2023/01/24 18:32:31 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_image(char *path, void *pid)
{
	int		ssize;
	void	*ldimg;

	ssize = 64;
	ldimg = mlx_xpm_file_to_image(pid, path, &ssize, &ssize);
	if (ldimg == NULL)
	{
		ft_printf("%s is missing! Abort...\n", path);
		exit (1);
	}
	ft_printf("\rLoaded image %s\r", path);
	return (ldimg);
}

void	load_images(void *g)
{
	t_mlxdata	*data;

	data = (t_mlxdata *)g;
	data->imgs.player = load_image("./assets/MikaSprites.xpm", data->pid);
	data->imgs.coins = load_image("./assets/MikaCrystalV3.xpm", data->pid);
	data->imgs.walls = load_image("./assets/Wall3.xpm", data->pid);
	data->imgs.exit = load_image("./assets/Exit2.xpm", data->pid);
	data->imgs.bg = load_image("./assets/Floor2.xpm", data->pid);
	data->imgs.foe = load_image("./assets/foe.xpm", data->pid);
}
