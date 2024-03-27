/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:14:06 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/17 19:34:33 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_sort(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}
