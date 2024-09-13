/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eng_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:16:16 by hle-hena          #+#    #+#             */
/*   Updated: 2024/09/13 20:48:51 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENG_TEST_H
# define ENG_TEST_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <stdio.h>

typedef struct s_word
{
	char	*fr;
	char	*eng;
	int		fr_to_eng;
	int		eng_to_fr;
}	t_word;

typedef struct s_quest
{
	char			*question;
	char			*answer;
	struct s_quest	*next;
}	t_quest;

void	ft_putstr_fd(char *str, int fd);
void	*ft_calloc(size_t n, size_t size);
void	*ft_realloc(void *ptr, size_t new_size);
size_t	ft_strlen(const char *str);
char	*ft_strcat(char *dest, char *src);

char	**ft_split(const char *str, char c);
char	*ft_strdup_se(const char *src, int s, int e);

void	free_error(char **strs);
void	free_strs(char **strs);
void	free_words(t_word **words);

t_quest	*ft_lstnew(void *question, void *answer);
void	ft_lstadd_back(t_quest **lst, t_quest *new);
void	ft_lstiter(t_quest **lst, int (*f)(char *, char *));
void	ft_lstclear(t_quest **lst, void (*del)(char *, char *));

int		random_quest(t_word *words, unsigned int seed, t_quest **head);
int		print_quest(char *question, char *answer);
void	clear_quest(char *question, char *answer);

#endif