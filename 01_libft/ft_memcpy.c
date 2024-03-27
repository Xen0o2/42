/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:08:31 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/06 20:29:28 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void		*original_dst;

	if (!dst && !src)
		return (NULL);
	original_dst = dst;
	while (n--)
		(*(char *)dst++) = (*(const char *)src++);
	return (original_dst);
}
