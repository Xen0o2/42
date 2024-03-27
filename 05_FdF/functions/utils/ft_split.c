/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:11:44 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/11 21:59:13 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	in_sep(char c, char *sep)
{
	while (*sep)
	{
		if (*sep == c)
			return (1);
		sep++;
	}
	return (0);
}

int	get_sep_nbr(char const *s, char *sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (in_sep(*s, sep))
			s++;
		if (!in_sep(*s, sep) && *s)
		{
			count++;
			while (!in_sep(*s, sep) && *s)
				s++;
		}
	}
	return (count + 1);
}

char	*create_malloc(char **tab, int length)
{
	*tab = malloc((length + 1) * sizeof(char));
	if (!*tab)
		return (NULL);
	return (*tab);
}

char	**ft_freeall(char **tab, int length)
{
	int	i;

	i = 0;
	while (i < length)
		free(tab[i++]);
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char *sep)
{
	t_split	all;

	if (!s)
		return (0);
	all.sep = get_sep_nbr(s, sep);
	all.tab = malloc(all.sep * sizeof(char *));
	if (!all.tab)
		return (NULL);
	all.i = 0;
	while (all.i < all.sep - 1)
	{
		all.j = 0;
		while (*s && in_sep(*s, sep))
			s++;
		all.length = next_word_length(s, sep);
		if (!create_malloc(&all.tab[all.i], all.length))
			return (ft_freeall(all.tab, all.i));
		while (all.j < all.length)
			all.tab[all.i][all.j++] = *s++;
		all.tab[all.i++][all.j] = 0;
	}
	all.tab[all.i] = 0;
	return (all.tab);
}
