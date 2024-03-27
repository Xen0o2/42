/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:01:42 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/12 18:06:02 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*cpy;

	length = ft_strlen(s1);
	cpy = malloc((length + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (*s1)
		*cpy++ = *s1++;
	*cpy = 0;
	return (cpy - length);
}
