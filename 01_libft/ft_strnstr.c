/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:05:07 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/05 23:22:58 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	temp;
	size_t	length;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	length = 0;
	while (needle[length])
		length++;
	while (i < len && *haystack)
	{
		temp = 0;
		if (*haystack == needle[temp])
		{
			while ((needle[temp] && needle[temp] == haystack[temp])
				&& (i + temp < len))
				temp++;
			if (temp == length)
				return ((char *)haystack);
		}
		haystack++;
		i++;
	}
	return (0);
}
