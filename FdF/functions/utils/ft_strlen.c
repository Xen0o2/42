/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:49:17 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/15 16:48:57 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	ft_strlen(char *s)
{
	int	length;

	length = 0;
	while (*s++)
		length++;
	return (length);
}

int	next_word_length(char const *s, char *sep)
{
	int	length;

	length = 0;
	while (*s && in_sep(*s, sep))
		s++;
	while (*s && !in_sep(*s, sep))
	{
		s++;
		length++;
	}
	return (length);
}
