/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:55:13 by fclivaz           #+#    #+#             */
/*   Updated: 2022/10/20 17:53:37 by fclivaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*a;

	a = (char *)malloc(count * size);
	if (a == NULL)
		return (a);
	ft_bzero(a, size * count);
	return ((void *)a);
}
