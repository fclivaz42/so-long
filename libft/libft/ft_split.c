/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:42:29 by fclivaz           #+#    #+#             */
/*   Updated: 2022/10/31 17:51:39 by fclivaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*splotch(char *str, char c)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			break ;
		i++;
	}
	ret = (char *)malloc(i * sizeof(char) + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			break ;
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static int	countwords(char const *str, char c)
{
	int	i;
	int	words;
	int	bingo;

	words = 0;
	i = 0;
	bingo = 0;
	while (str[i] != 0)
	{
		if (str[i] != c && bingo == 0)
		{
			words++;
			bingo = 1;
		}
		else if (str[i] == c)
			bingo = 0;
		i++;
	}	
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**ee;
	char	*str;
	size_t	word;
	size_t	x;

	x = 0;
	str = (char *)s;
	word = countwords(s, c);
	ee = (char **)malloc((word + 1) * sizeof(char *));
	if (ee == NULL)
		return (NULL);
	while (word-- != 0)
	{
		while (*str == c)
			str++;
		ee[x++] = splotch(str, c);
		while (*str != c)
		{
			if (*str == 0)
				break ;
			str++;
		}
	}
	ee[x] = 0;
	return (ee);
}
