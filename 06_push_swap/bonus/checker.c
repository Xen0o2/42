/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:37:45 by alecoutr          #+#    #+#             */
/*   Updated: 2023/05/04 15:10:37 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	fill_stack(t_stack **stack, int ac, char **av)
{
	int				i;
	long long int	number;

	*stack = NULL;
	i = 1;
	while (av[i])
	{
		number = ft_atoi(av[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (0);
		if (i == 1)
			*stack = new_stack(number);
		else
			add_bottom_stack(stack, new_stack((int) number));
		i++;
	}
	return (1);
}

void	do_move(char *move, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(move, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(move, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(move, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(move, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(move, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (ft_strcmp(move, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(move, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(move, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(move, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(move, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(move, "ss\n") == 0)
		ss(stack_a, stack_b);
}

void	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*tmp;

	tmp = get_next_line(0);
	while (tmp)
	{
		do_move(tmp, stack_a, stack_b);
		free(tmp);
		tmp = get_next_line(0);
	}
	free(tmp);
	if (is_sorted(*stack_a) && get_stack_size(*stack_b) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			i;

	if (!check_input(av))
		exit_error();
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || ac == 2)
		exit(1);
	if (!fill_stack(&stack_a, ac, av))
		exit_error();
	checker(&stack_a, &stack_b);
}
