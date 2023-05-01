/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:15:42 by fclivaz           #+#    #+#             */
/*   Updated: 2023/01/24 21:15:51 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_fortmat(char *arg)
{
	int	argie;

	if (!ft_strncmp(ft_strrchr(arg, 0) - 4, ".ber", ft_strlen(arg)))
	{
		argie = open(arg, O_RDONLY);
		return (argie);
	}
	ft_printf("\033[1;33mError:\033[0m\n");
	ft_printf("\033[1;31mUnsupported file format.\033[0m\n");
	exit (1);
}

static int	check_args(int args, char **argv)
{
	int	fd;

	if (args < 2)
	{
		ft_printf("\033[1;33mError:\033[0m\n");
		ft_printf("\033[1;31mMap is missing!\033[0m\n");
		exit (1);
	}
	else if (args > 2)
	{
		ft_printf("\033[1;33mError:\033[0m\n");
		ft_printf("\033[1;31mToo many arguments.\033[0m\n");
		exit (1);
	}
	else
		fd = check_fortmat(argv[1]);
	return (fd);
}

static void	check_rectangular(int fd, void *g)
{
	char		*final;
	char		*tmp;
	int			len;
	t_mlxdata	*data;

	data = (t_mlxdata *)g;
	tmp = get_next_line(fd);
	if (tmp == NULL)
		error_pre_map(0, tmp);
	len = maplen(tmp);
	final = ft_strdup(tmp);
	while (tmp != NULL)
	{
		if (maplen(tmp) != len)
			error_pre_map(1, tmp);
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp != NULL)
			final = ft_gnljoin(final, tmp);
	}
	data->map = ft_split(final, '\n');
	free(final);
}

void	check_valid_map(int argc, char **argv, void *g)
{
	t_mlxdata	*data;
	int			fd;

	data = (t_mlxdata *)g;
	ft_printf("Checking map validity of '%s'.\n", argv[1]);
	fd = check_args(argc, argv);
	check_rectangular(fd, (void *)data);
	close(fd);
	map_validator((void *)data);
	ft_printf("\033[1;32mMap is valid! Launching game.\033[0m\n");
}

/*
void	print_map(char **map)
{
	int y;

	y = -1;
	ft_printf("------------------------\n");
	while (map[++y] != NULL)
		ft_printf("%s\n", map[y]);
	ft_printf("------------------------\n");
}*/