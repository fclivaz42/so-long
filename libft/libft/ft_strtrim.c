/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:31:10 by fclivaz           #+#    #+#             */
/*   Updated: 2022/10/28 17:39:00 by fclivaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	findfront(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (ft_strchr(set, str[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	findend(char const *str, char const *set)
{
	int	i;

	i = ft_strlen(str);
	while (i != 0)
	{
		if (ft_strchr(set, str[i]) == 0)
		{
			return (i);
		}
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = findfront(s1, set);
	end = findend(s1, set);
	if (end - start < 0)
	{
		ret = (char *)malloc(1);
		ret[0] = 0;
		return (ret);
	}
	ret = (char *)malloc(end - start + 2);
	if (ret == NULL)
		return (NULL);
	while (s1[i + start] != 0 && i != end - start + 1)
	{
		ret[i] = s1[i + start];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
