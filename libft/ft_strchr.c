/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:17:34 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/12 18:02:52 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ss;
	char	cc;

	ss = (char *)s;
	cc = (char)c;
	while (*ss)
	{
		if (*ss == cc)
			return (ss);
		ss++;
	}
	if (*ss == cc)
		return (ss);
	return (NULL);
}
