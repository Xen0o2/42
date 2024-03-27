/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:37:30 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/04 17:10:21 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	return_length;
	size_t	dest_length;

	dest_length = 0;
	while (dest_length < dstsize && dst[dest_length])
		dest_length++;
	return_length = ft_strlen(src) + dest_length;
	dst += dest_length;
	if (dstsize != dest_length)
	{
		while (*src)
		{
			if (dstsize > dest_length + 1)
			{
				*dst++ = *src;
				dstsize--;
			}
			src++;
		}
		*dst = 0;
	}
	return (return_length);
}
