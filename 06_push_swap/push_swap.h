/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:24:34 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/24 00:23:47 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				a_cost;
	int				b_cost;
	int				cost;
	struct s_stack	*next;
}	t_stack;

t_stack			*new_stack(int value);
t_stack			*get_bottom_stack(t_stack *stack);
t_stack			*get_pre_bottom_stack(t_stack *stack);
void			add_bottom_stack(t_stack **stack, t_stack *new);
int				get_stack_size(t_stack *stack);

void			select_algo(t_stack **stack_a, t_stack **stack_b);
int				is_sorted(t_stack *stack);
void			two_sort(t_stack **stack_a);
void			tree_sort(t_stack **stack_a);
void			little_sort(t_stack **stack_a, t_stack **stack_b);
void			big_sort(t_stack **stack_a, t_stack **stack_b);

// BIG SORT
void			swap_values(t_stack *a, t_stack *b);
void			bubble_sort(t_stack **stack);
int				duplicate(t_stack *stack, t_stack **duplicate);
int				get_middle(t_stack *stack);
void			push_b(t_stack **stack_a, t_stack **stack_b);

// BIG SORT 2
void			get_b_costs(t_stack *stack_b);
int				get_tiny_position(t_stack **stack);
int				find_moves(t_stack *stack_a, int value, int size);
void			get_a_costs(t_stack *stack_a, t_stack *stack_b);
int				get_best_position(t_stack *stack_b);

// BIG SORT 3
void			get_moves(t_stack *stack_b, int *nb_ra,
					int *nb_rb, int best_position);
void			big_sort(t_stack **stack_a, t_stack **stack_b);

long long int	ft_atoi(char *s);
int				ft_strcmp(char *s1, char *s2);
char			*remove_zero(char *s1);
int				is_number(char *str);
int				is_double(char **av, int i);
int				check_input(char **av);
void			ft_putstr(char *str);
int				abs(int n);
int				is_sorted(t_stack *stack);

void			ss(t_stack **stack_a, t_stack **stack_b);
void			sa(t_stack **stack_a);
void			sb(t_stack **stack_b);

void			pa(t_stack **stack_a, t_stack **stack_b);
void			pb(t_stack **stack_a, t_stack **stack_b);

void			rr(t_stack **stack_a, t_stack **stack_b);
void			ra(t_stack **stack_a);
void			rb(t_stack **stack_b);

void			rrr(t_stack **stack_a, t_stack **stack_b);
void			rra(t_stack **stack_a);
void			rrb(t_stack **stack_b);

#endif