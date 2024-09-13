/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:20:30 by hle-hena          #+#    #+#             */
/*   Updated: 2024/09/13 12:07:48 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eng_test.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i ++;
	return (i);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*dest;
	size_t	i;

	dest = malloc(n * size);
	if (!dest)
		return (0);
	i = 0;
	while (i < n * size)
	{
		((char *) dest)[i] = 0;
		i ++;
	}
	return (dest);
}

void	*ft_realloc(void *ptr, size_t new_size)
{
	char		*new_ptr;
	size_t		i;

	i = 0;
	new_ptr = ft_calloc(new_size, sizeof(char));
	while (((char *)ptr)[i])
	{
		new_ptr[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
		write (fd, str++, 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j] != '\0' && src[j] != '\n')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
