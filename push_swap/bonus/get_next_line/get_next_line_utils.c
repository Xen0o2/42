/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:52:52 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/25 00:52:58 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
		if (*s++ == c)
			return (s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	t_join	all;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (0);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	all.result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!all.result)
		return (0);
	all.i = 0;
	all.x = 0;
	while (s1[all.i])
		all.result[all.x++] = s1[all.i++];
	all.i = 0;
	while (s2[all.i])
		all.result[all.x++] = s2[all.i++];
	all.result[all.x] = 0;
	free(s1);
	return (all.result);
}
