/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:39:05 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/07 09:45:52 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T	*tab, int size, void (*func)(T &))
{
	if (!tab || !func)
		return ;
	for(int i = 0; i < size; i++)
		func(tab[i]);
}

#endif
