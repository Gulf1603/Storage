/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eng_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:14:03 by hle-hena          #+#    #+#             */
/*   Updated: 2024/09/13 20:53:08 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eng_test.h"

t_quest	*create_quest(t_word **words)
{
	t_quest			*head;
	int				i;
	int				added;
	time_t			curr_time;
	unsigned int	seed;

	head = NULL;
	curr_time = time(NULL);
	seed = (unsigned int) curr_time;
	while (1)
	{
		i = 0;
		added = 0;
		while ((*words)[i].eng)
		{
			seed = seed * 19487 + 1328497 / 10000;
			added += random_quest(&(*words)[i], seed, &head);
			i ++;
		}
		if (!added)
			break ;
	}
	free_words(words);
	return (head);
}

t_word	*parse(char *f_content)
{
	t_word	*words;	
	char	**splited;
	char	**question;
	int		i;

	splited = ft_split(f_content, '\n');
	i = -1;
	while (splited[++i]);
	words = ft_calloc(i + 1, sizeof(t_word));
	i = 0;
	while (splited[i])
	{
		question = ft_split(splited[i], ':');
		if (!question[0] || !question[1])
			return (free_strs(splited), free_words(&words),
						free_error(question), NULL);
		words[i].eng = ft_strdup_se(question[0], 0, ft_strlen(question[0]));
		words[i].fr = ft_strdup_se((question[1]),  0, ft_strlen(question[1]));
		free_strs(question);
		i ++;
	}
	words[i].fr = NULL;
	words[i].eng = NULL;
	free_strs(splited);
	return (words);
}

//words not freed
void	init_quiz(char *f_content)
{
	t_quest	*head;
	t_quest	*head_cpy;
	t_word	*words;

	words = parse(f_content);
	free(f_content);
	if (!words)
	{
		ft_putstr_fd("The words file doesnt follow the format required\n", 1);
		ft_putstr_fd("If more information is needed, contact your love :D\n", 1);
		return ;
	}
	head = create_quest(&words);
	head_cpy = head;
	ft_lstiter(&head_cpy, &print_quest);
	ft_putstr_fd("\n\n\n\nCongrats ! The test is finished !\n", 1);
	ft_lstclear(&head, &clear_quest);
}

size_t	get_file_size(int fd)
{
	char	buffer[100];
	size_t	rv;
	size_t	tot;

	tot = read(fd, buffer, 100);
	rv = tot;
	while (rv)
	{
		rv = read(fd, buffer, 100);
		tot += rv;
	}
	return (tot);
}

int main(int ac, char **av)
{
	int		fd;
	size_t	f_size;
	char	*f_content;
	
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (ft_putstr_fd("File does not exist\n", 1), 1);
		f_size = get_file_size(fd);
		close(fd);
		open(av[1], O_RDONLY);
		f_content = ft_calloc(f_size + 1, sizeof(char));
		read(fd, f_content, f_size);
		close(fd);
		return (init_quiz(f_content), 1);
	}
	return (ft_putstr_fd("Not enough or too much arguments passed\n", 1), 1);
}