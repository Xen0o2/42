/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:42:41 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/07 09:47:00 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void	func(T &value)
{
	value *= 2;
}

int main( void )
{
	int	tab[5] = { 1, 2, 3, 4, 5};
	iter(tab, 5, &func);
	for(int i = 0; i < 5; i++)
		std::cout << tab[i] << std::endl;
}
