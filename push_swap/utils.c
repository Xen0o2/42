/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:43:59 by alecoutr          #+#    #+#             */
/*   Updated: 2023/03/27 14:54:41 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:49:33 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/06 20:30:16 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoi(char *s)
{
	long long int	result;
	int				sign;

	result = 0;
	sign = 1;
	while ((*s == ' ' || *s == '\r' || *s == '\t')
		|| (*s == '\n' || *s == '\v' || *s == '\f'))
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

char	*remove_zero(char *s1)
{
	int	i;
	int	zero_count;
	int	past;

	i = 0;
	zero_count = 0;
	past = 0;
	while (s1[i] && s1[i + 1])
	{
		if (s1[i] != '0')
			past = 1;
		if (s1[i] == '0' && !past)
			zero_count++;
		i++;
	}
	return (s1 + zero_count);
}

int	ft_strcmp(char *s1, char *s2)
{
	s1 = remove_zero(s1);
	s2 = remove_zero(s2);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, &*str++, 1);
}

int	abs(int n)
{
	if (n < 0)
		return (-(n));
	else
		return (n);
}
