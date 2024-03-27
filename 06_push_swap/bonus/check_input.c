/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:37:46 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/25 22:50:46 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

int	is_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if ((str[i] < '0' || str[i] > '9')
			&& (i != 0 || (str[i] != '+' && str[i] != '-')))
			return (0);
	return (1);
}

int	is_double(char **av, int i)
{
	int	j;

	j = -1;
	while (av[++j])
		if (ft_strcmp(av[i], av[j]) == 0 && i != j)
			return (1);
	return (0);
}

int	check_input(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (is_double(av, i) || !is_number(av[i]))
			return (0);
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
