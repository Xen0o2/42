/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:55:47 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/12 17:08:00 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cpy;

	cpy = *lst;
	while (cpy)
	{
		if (!cpy->next)
		{
			cpy->next = new;
			return ;
		}
		cpy = cpy->next;
	}
	*lst = new;
}
