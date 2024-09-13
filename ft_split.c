/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:45:57 by hle-hena          #+#    #+#             */
/*   Updated: 2024/09/12 19:46:20 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eng_test.h"

char	*ft_strdup_se(const char *src, int s, int e)
{
	char	*dest;
	int	i;

	if (e - s < 0)
		return (0);
	dest = ft_calloc(e - s + 2, sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (i < e - s + 1)
	{
		dest[i] = src[s + i];
		i ++;
	}
	dest[i] = 0;
	return (dest);
}


int	count_words(const char *str, char c)
{
	int		s;
	int		e;
	int		i;

	i = 0;
	s = 0;
	e = 0;
	while (str[e])
	{
		while (str[e] && str[e] == c)
			e ++;
		s = e;
		while (str[e] && str[e] != c)
			e ++;
		if (s < e)
			i ++;
	}
	return(i);
}

void	freeing_splited(char **splited, int i)
{
	while (i >= 0)
	{
		free(splited[i]);
		i --;
	}
	free(splited);
}

char	**ft_split(const char *str, char c)
{
	char	**splited;
	int		s;
	int		e;
	int		i;

	i = 0;
	s = 0;
	e = 0;
	if (!(splited = ft_calloc(count_words(str, c) + 1, sizeof(char *))))
		return (0);
	while (str[e])
	{
		while (str[e] && str[e] == c)
			e ++;
		s = e;
		while (str[e] && str[e] != c)
			e ++;
		if (s < e)
		{
			if (!(splited[i ++] = ft_strdup_se(str, s, e - 1)))
				return (freeing_splited(splited, i), NULL);
		}
	}
	splited[i] = 0;
	return (splited);
}
