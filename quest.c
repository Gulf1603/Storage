/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:45:49 by hle-hena          #+#    #+#             */
/*   Updated: 2024/09/13 20:51:34 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eng_test.h"

int	random_quest(t_word *words, unsigned int seed, t_quest **head)
{
	t_quest	*res;

	res = NULL;
	if (seed % 100 < 25 && !((*words).eng_to_fr))
	{
		res = ft_lstnew((*words).eng, (*words).fr);
		(*words).eng_to_fr = 1;
	}
	else if (seed % 100 < 50 && !((*words).fr_to_eng))
	{
		res = ft_lstnew((*words).fr, (*words).eng);
		(*words).fr_to_eng = 1;
	}
	if (res)
	{
		if (!(*head))
			*head = res;
		else
			ft_lstadd_back(head, res);
	}
	if (!((*words).eng_to_fr) || !((*words).fr_to_eng))
		return (1);
	return (0);
}

int	print_quest(char *question, char *answer)
{
	char	buffer[100];
	char	*try;
	int		rv;
	int		i;

	ft_putstr_fd("\n\nWhat is the traduction of '", 1);
	ft_putstr_fd(question, 1);
	ft_putstr_fd("' ?\n", 1);
	try = ft_calloc(1, sizeof(char));
	while (1)
	{
		rv = read(0, buffer, 99);
		buffer[rv] = 0;
		try = ft_realloc(try, ft_strlen(try) + rv + 1);
		ft_strcat(try, buffer);
		if (rv != 99)
			break;
	}
	i = 0;
	while (answer[i] == try[i] && try[i])
		i ++;
	if (!answer[i] && answer[i] == try[i])
		return (free(try), 0);
	ft_putstr_fd("False answer, adding it back to the list\n", 1);
	return (free(try), 1);
}

void	clear_quest(char *question, char *answer)
{
	free(question);
	question = NULL;
	free(answer);
	answer = NULL;
}