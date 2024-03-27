/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:13:06 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/12 18:15:42 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cpy;
	t_list	*swap;

	if (lst && del)
	{
		cpy = *lst;
		while (cpy)
		{
			del(cpy->content);
			swap = cpy->next;
			free(cpy);
			cpy = swap;
		}
		*lst = 0;
	}
}
