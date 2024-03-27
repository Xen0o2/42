/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:54:23 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 12:02:05 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	this->_name = name;
	std::cout << this->_name << " has been created" << std::endl;
	return;
}

Zombie::Zombie( void )
{
	std::cout << "New Zombie has been created" << std::endl;
	return;
}

Zombie::~Zombie( void )
{
	std::cout << this->_name << " has been deleted" << std::endl;
	return;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name)
{
	this->_name = name;
}

std::string	Zombie::getName( void )
{
	return (this->_name);
}
