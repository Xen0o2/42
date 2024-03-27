/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:18:09 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/26 00:02:35 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*before_last_stack;
	t_stack	*last_stack;

	if (stack == NULL || *stack == NULL)
		return ;
	before_last_stack = get_pre_bottom_stack(*stack);
	last_stack = get_bottom_stack(*stack);
	before_last_stack->next = NULL;
	last_stack->next = *stack;
	*stack = last_stack;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
}
