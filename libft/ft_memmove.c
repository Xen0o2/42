/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:01:32 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/06 20:30:33 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cpydst;
	char	*cpysrc;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	cpydst = (char *)dst;
	cpysrc = (char *)src;
	i = 0;
	if (cpysrc < cpydst)
		while (len--)
			*(cpydst + len) = *(cpysrc + len);
	else
	{
		while (i < len)
		{
			cpydst[i] = cpysrc[i];
			i++;
		}
	}
	return (dst);
}
