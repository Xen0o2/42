/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:19:09 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/17 19:33:55 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_pos_little(t_stack **stack_a)
{
	int		i;
	int		pos;
	int		tmp;
	t_stack	*tmp_stack;

	i = 0;
	pos = 0;
	tmp = (*stack_a)->value;
	tmp_stack = *stack_a;
	while (tmp_stack)
	{
		if (tmp_stack->value < tmp)
		{
			pos = i;
			tmp = tmp_stack->value;
		}
		i++;
		tmp_stack = tmp_stack->next;
	}
	return (pos);
}

void	little_first(t_stack **stack_a)
{
	int	position;
	int	size;

	position = find_pos_little(stack_a);
	size = get_stack_size(*stack_a);
	if (position >= size / 2)
		position = -(size - position);
	while (position)
	{
		if (position > 0)
		{
			ra(stack_a);
			position--;
		}
		else
		{
			rra(stack_a);
			position++;
		}
	}
}

void	little_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (get_stack_size(*stack_a) > 3)
	{
		little_first(stack_a);
		pb(stack_a, stack_b);
	}
	tree_sort(stack_a);
	pa(stack_a, stack_b);
	if (stack_b)
		pa(stack_a, stack_b);
}
