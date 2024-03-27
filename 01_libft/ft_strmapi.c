/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:13:58 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/11 21:58:57 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	length;
	size_t	i;

	if (!s)
		return (0);
	length = ft_strlen(s);
	result = malloc((length + 1) * sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (*s)
		*result++ = f(i++, *s++);
	*result = 0;
	return (result - length);
}
