/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:12:08 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 15:24:21 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ): _name(name), _weapon(NULL)
{
	std::cout << "Human B " << name << " created" << std::endl;
	return;
}

HumanB::~HumanB( void )
{
	std::cout << "Human B " << this->_name << " destroyed" << std::endl;
	return;
}

void	HumanB::attack( void )
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
}
