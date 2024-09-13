/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:24:37 by hle-hena          #+#    #+#             */
/*   Updated: 2024/09/13 20:48:29 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eng_test.h"

void	free_error(char **strs)
{
	if (strs[0])
		free(strs[0]);
	free(strs);
}

void	free_words(t_word **words)
{
	int	i;

	i = 0;
	while ((*words)[i].eng)
	{
		free((*words)[i].eng);
		free((*words)[i].fr);
		i ++;
	}
	free(*words);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i ++;
	}
	free(strs);
}