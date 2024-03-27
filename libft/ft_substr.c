/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:02:09 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/12 18:05:49 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*final;
	size_t	length;
	size_t	i;

	if (!s)
		return (0);
	length = ft_strlen(s);
	if (len > length)
		len = length;
	if (start >= length)
		len = 0;
	if (len > length - start)
		len = length - start;
	final = malloc((len + 1) * sizeof(char));
	if (!final)
		return (0);
	i = -1;
	while (++i < len)
		final[i] = s[i + start];
	final[i] = 0;
	return (final);
}
