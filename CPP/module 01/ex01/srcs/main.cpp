/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:56:16 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 12:03:39 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	int	size = 10;
	Zombie *horde = zombieHorde(size, "Alexandre");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
}
