/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:32:24 by hle-hena          #+#    #+#             */
/*   Updated: 2024/09/13 12:39:54 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eng_test.h"

t_quest	*ft_lstlast(t_quest *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_quest **lst, t_quest *new)
{
	t_quest	*last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

t_quest	*ft_lstnew(void *question, void *answer)
{
	t_quest	*head;

	head = ft_calloc(1, sizeof(t_quest));
	if (!head)
		return (NULL);
	head->question = ft_strdup_se(question, 0, ft_strlen(question));
	head->answer = ft_strdup_se(answer, 0, ft_strlen(answer));
	head->next = NULL;
	return (head);
}

void	ft_lstiter(t_quest **lst, int (*f)(char *, char *))
{
	while (*lst)
	{
		if (f((*lst)->question, (*lst)->answer))
			ft_lstadd_back(lst, ft_lstnew((*lst)->question, (*lst)->answer));
		*lst = (*lst)->next;
	}
}

void	ft_lstclear(t_quest **lst, void (*del)(char *, char *))
{
	t_quest	*temp;

	while(*lst)
	{
		temp = (*lst)->next;
		del((*lst)->question, (*lst)->answer);
		free(*lst);
		*lst = temp;
	}
	*lst = 0;
}