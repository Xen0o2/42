/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:42:24 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/11 21:12:34 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_length(int n, int *sign)
{
	int	length;

	length = 0;
	if (n == -2147483648)
	{
		*sign = -1;
		return (11);
	}
	else if (n < 0)
	{
		*sign = -1;
		length++;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int				length;
	char			*result;
	unsigned int	nn;
	int				sign;
	int				i;

	sign = 1;
	length = ft_nb_length(n, &sign);
	result = malloc((length + 1) * sizeof(char));
	if (!result)
		return (0);
	nn = n * sign;
	if (nn == 0)
		result[0] = '0';
	i = 1;
	while (nn)
	{
		result[length - i++] = (nn % 10) + '0';
		nn /= 10;
	}
	if (sign == -1)
		result[0] = '-';
	result[length] = 0;
	return (result);
}
