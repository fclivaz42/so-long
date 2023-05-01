/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:24:29 by fclivaz           #+#    #+#             */
/*   Updated: 2023/02/08 13:24:37 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_steps(void *g)
{
	t_mlxdata	*data;
	char		*str;
	void		*pid;
	void		*wid;
	int			*wsize;

	data = (t_mlxdata *)g;
	pid = data->pid;
	wid = data->wid;
	wsize = data->wsize;
	str = "Steps: ";
	str = ft_strjoin(str, ft_itoa(data->pdata.steps));
	mlx_put_image_to_window(pid, wid, data->imgs.walls, 64, wsize[1] - 64);
	mlx_put_image_to_window(pid, wid, data->imgs.walls, 64 * 2, wsize[1] - 64);
	mlx_string_put(pid, wid, 64 + 16, wsize[1] - 32, 0xFFFFFF, str);
	ft_printf("Steps: %d\r", data->pdata.steps);
	free(str);
}

void	display_collectible(void *g)
{
	t_mlxdata	*data;
	char		*str;
	void		*pid;
	void		*wid;
	int			*wsize;

	data = (t_mlxdata *)g;
	pid = data->pid;
	wid = data->wid;
	wsize = data->wsize;
	str = "Prisms: ";
	str = ft_strjoin(str, ft_itoa(data->pdata.score));
	mlx_put_image_to_window(pid, wid, data->imgs.walls, 192, wsize[1] - 64);
	mlx_put_image_to_window(pid, wid, data->imgs.walls, 256, wsize[1] - 64);
	mlx_string_put(pid, wid, 128 + 16 + 64, wsize[1] - 32, 0xFFFFFF, str);
	ft_printf("Collected a Prism! Total: %d\n", data->pdata.score);
	free(str);
}
