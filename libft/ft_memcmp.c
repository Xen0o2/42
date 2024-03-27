/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 22:28:26 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/05 22:28:58 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*other1;
	char	*other2;

	other1 = (char *)s1;
	other2 = (char *)s2;
	while (n && *other1 == *other2)
	{
		other1++;
		other2++;
		n--;
	}
	if (n)
		return ((unsigned char)*other1 - (unsigned char)*other2);
	else
		return (0);
}
