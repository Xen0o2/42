/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:37:56 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/25 23:59:49 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_instruction
{
	char					*value;
	struct s_instruction	*next;
}	t_instruction;

typedef struct s_join
{
	char	*result;
	int		i;
	int		x;
}	t_join;

char			*get_next_line(int fd);
int				check_input(char **av);
int				fill_stack(t_stack **stack, int ac, char **av);
long long int	ft_atoi(char *s);
char			*remove_zero(char *s1);
int				ft_strcmp(char *s1, char *s2);
void			ft_putstr(char *str);
int				abs(int n);
t_stack			*new_stack(int value);
t_stack			*get_bottom_stack(t_stack *stack);
t_stack			*get_pre_bottom_stack(t_stack *stack);
void			add_bottom_stack(t_stack **stack, t_stack *new);
int				get_stack_size(t_stack *stack);
char			*ft_strchr(char *s, char c);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *s);
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