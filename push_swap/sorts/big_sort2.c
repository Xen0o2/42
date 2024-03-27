/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:50:40 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/23 23:53:16 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_values(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

void	bubble_sort(t_stack **stack)
{
	int		swapped;
	t_stack	*tmp_stack;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		tmp_stack = *stack;
		while (tmp_stack->next)
		{
			if (tmp_stack->value > tmp_stack->next->value)
			{
				swap_values(tmp_stack, tmp_stack->next);
				swapped = 1;
			}
			tmp_stack = tmp_stack->next;
		}
	}
}

int	duplicate(t_stack *stack, t_stack **duplicate)
{
	int	i;

	*duplicate = NULL;
	i = 1;
	while (stack)
	{
		if (i == 1)
			*duplicate = new_stack(stack->value);
		else
			add_bottom_stack(duplicate, new_stack(stack->value));
		i++;
		stack = stack->next;
	}
	bubble_sort(duplicate);
	return (i);
}

int	get_middle(t_stack *stack)
{
	t_stack	*duplicate_stack;
	t_stack	*address;
	int		size;
	int		value;

	size = duplicate(stack, &duplicate_stack) / 2;
	while (--size)
	{
		address = duplicate_stack->next;
		free(duplicate_stack);
		duplicate_stack = address;
	}
	value = duplicate_stack->value;
	while (duplicate_stack)
	{
		address = duplicate_stack->next;
		free(duplicate_stack);
		duplicate_stack = address;
	}
	return (value);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	int		middle;
	int		size;
	int		i;
	t_stack	*tmp_stack;

	tmp_stack = *stack_a;
	i = -1;
	size = get_stack_size(*stack_a) + 1;
	middle = get_middle(*stack_a);
	while (++i < size)
	{
		if (tmp_stack->value <= middle)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		tmp_stack = *stack_a;
	}
	while (get_stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
	tree_sort(stack_a);
}
