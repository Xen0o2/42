/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 22:23:37 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/05 22:24:40 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*ss;

	cc = (unsigned char)c;
	ss = (unsigned char *)s;
	while (n)
	{
		if (*ss == cc)
			return (ss);
		n--;
		ss++;
	}
	return (0);
}
