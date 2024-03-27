/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:23:30 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/17 19:35:18 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	select_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size == 2)
		two_sort(stack_a);
	else if (size == 3)
		tree_sort(stack_a);
	else if (size == 4 || size == 5)
		little_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}
