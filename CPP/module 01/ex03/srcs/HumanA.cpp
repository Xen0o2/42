/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:10:18 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 13:35:34 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ): _name(name), _weapon(weapon)
{
	std::cout << "Human A " << name << " created with " << weapon.getType() << std::endl;
	return;
}

HumanA::~HumanA( void )
{
	std::cout << "Human A " << this->_name << " destroyed" << std::endl;
	return;
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
