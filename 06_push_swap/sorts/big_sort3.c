/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:53:35 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/24 00:10:32 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_b_costs(t_stack *stack_b)
{
	int	size;
	int	i;

	size = get_stack_size(stack_b);
	i = 0;
	while (stack_b)
	{
		if (i > size / 2)
			stack_b->b_cost = i - size;
		else
			stack_b->b_cost = i;
		i++;
		stack_b = stack_b->next;
	}
}

int	get_tiny_position(t_stack **stack)
{
	int		i;
	int		min;
	int		position;
	t_stack	*tmp_stack;

	i = 0;
	position = 0;
	min = INT_MAX;
	tmp_stack = *stack;
	while (tmp_stack)
	{
		if (tmp_stack->value < min)
		{
			min = tmp_stack->value;
			position = i;
		}
		i++;
		tmp_stack = tmp_stack->next;
	}
	return (position);
}

int	find_moves(t_stack *stack_a, int value, int size)
{
	int		i;
	int		gap;
	int		moves;
	t_stack	*tmp_stack;

	i = 0;
	gap = INT_MAX;
	tmp_stack = stack_a;
	while (tmp_stack)
	{
		if ((tmp_stack->value - value < gap)
			&& tmp_stack->value > value)
		{
			gap = tmp_stack->value - value;
			if (i > size / 2)
				moves = i - size;
			else
				moves = i;
		}
		i++;
		tmp_stack = tmp_stack->next;
	}
	if (gap == INT_MAX)
		moves = get_tiny_position(&stack_a);
	return (moves);
}

void	get_a_costs(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		gap;
	int		moves;
	int		size;

	moves = 0;
	size = get_stack_size(stack_a);
	while (stack_b)
	{
		moves = find_moves(stack_a, stack_b->value, size);
		stack_b->a_cost = moves;
		stack_b->cost = abs(stack_b->a_cost) + abs(stack_b->b_cost);
		stack_b = stack_b->next;
	}
}

int	get_best_position(t_stack *stack_b)
{
	int	i;
	int	min;
	int	position;

	i = 0;
	min = stack_b->cost;
	position = 0;
	while (stack_b)
	{
		if (stack_b->cost < min)
		{
			min = stack_b->cost;
			position = i;
		}
		i++;
		stack_b = stack_b->next;
	}
	return (position);
}
