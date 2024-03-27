/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:19:43 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/12 17:59:02 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmpl;
	t_list	*new;
	void	*tmp;

	new = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		tmpl = ft_lstnew(tmp);
		if (!tmpl)
		{
			free(tmp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmpl);
		lst = lst->next;
	}
	return (new);
}
