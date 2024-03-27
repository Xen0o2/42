/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:36:13 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/24 00:24:01 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_moves(t_stack *stack_b, int *nb_ra, int *nb_rb, int best_position)
{
	int	i;

	i = -1;
	while (++i < best_position)
		stack_b = stack_b->next;
	*nb_ra = stack_b->a_cost;
	*nb_rb = stack_b->b_cost;
}

void	do_ra(t_stack **stack_a, int nb_ra)
{
	while (nb_ra)
	{
		if (nb_ra > 0)
		{
			ra(stack_a);
			nb_ra--;
		}
		else
		{
			rra(stack_a);
			nb_ra++;
		}
	}
}

void	do_rb(t_stack **stack_b, int nb_rb)
{
	while (nb_rb)
	{
		if (nb_rb > 0)
		{
			rb(stack_b);
			nb_rb--;
		}
		else
		{
			rrb(stack_b);
			nb_rb++;
		}
	}
}

void	finish(t_stack **stack_a)
{
	int	min;
	int	size;

	min = get_tiny_position(stack_a);
	size = get_stack_size(*stack_a);
	if (min > size / 2)
		min = - (size - min);
	while (min)
	{
		if (min > 0)
		{
			ra(stack_a);
			min--;
		}
		else
		{
			rra(stack_a);
			min++;
		}
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	best_position;
	int	nb_ra;
	int	nb_rb;

	push_b(stack_a, stack_b);
	while (*stack_b)
	{
		get_b_costs(*stack_b);
		get_a_costs(*stack_a, *stack_b);
		i = -1;
		best_position = get_best_position(*stack_b);
		get_moves(*stack_b, &nb_ra, &nb_rb, best_position);
		do_ra(stack_a, nb_ra);
		do_rb(stack_b, nb_rb);
		pa(stack_a, stack_b);
	}
	finish(stack_a);
}
