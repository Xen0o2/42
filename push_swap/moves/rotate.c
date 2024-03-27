/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:00:47 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/17 16:31:03 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*second_stack;
	t_stack	*last_stack;

	if (stack == NULL || *stack == NULL)
		return ;
	second_stack = (*stack)->next;
	last_stack = get_bottom_stack(*stack);
	last_stack->next = *stack;
	(*stack)->next = NULL;
	*stack = second_stack;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr("rr\n");
	ra(stack_a);
	rb(stack_b);
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}
