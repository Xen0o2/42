/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:56:16 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 11:31:39 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie	*zombie = newZombie("Alexandre");
	zombie->announce();
	randomChump("Bruno");
	delete zombie;
}
