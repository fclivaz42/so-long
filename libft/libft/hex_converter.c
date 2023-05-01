/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:37:28 by fclivaz           #+#    #+#             */
/*   Updated: 2022/11/24 21:03:45 by fclivaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*positive_hex(int i)
{
	int		nbr;
	int		index;
	char	*dict;
	char	*hex;

	dict = "0123456789abcdef";
	index = 0;
	nbr = i;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		index++;
	}
	hex = (char *)malloc((sizeof(char)) * (index + 1));
	if (hex == NULL)
		return (NULL);
	hex[index] = 0;
	index--;
	while (i > 0)
	{
		nbr = i % 16;
		hex[index--] = dict[nbr];
		i = i / 16;
	}
	return (hex);
}

static char	*negative_hex(int i)
{
	unsigned int	big;
	unsigned int	nbr;
	int				index;
	char			*dict;
	char			*hex;

	dict = "0123456789abcdef";
	nbr = UINT_MAX + i + 1;
	big = nbr;
	index = 8;
	hex = (char *)malloc((sizeof(char)) * (index + 1));
	if (hex == NULL)
		return (NULL);
	hex[8] = 0;
	index--;
	while (big > 1)
	{
		nbr = big % 16;
		hex[index--] = dict[nbr];
		big = big / 16;
	}
	return (hex);
}

int	print_hex(char str, int i)
{
	char	*print;
	int		k;

	k = 0;
	if (i == 0)
		return (write(1, "0", 1));
	if (i < 0)
		print = negative_hex(i);
	else
		print = positive_hex(i);
	if (str == 'x')
	{
		while (print[k] != 0)
			ft_putchar_fd(print[k++], 1);
	}
	if (str == 'X')
	{
		while (print[k] != 0)
			ft_putchar_fd(ft_toupper(print[k++]), 1);
	}
	free(print);
	return (k);
}
