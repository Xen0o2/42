/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:03:58 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 15:33:31 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ): _type(type)
{
	std::cout << "Weapon " << type << " created" << std::endl;
	return;
}

Weapon::~Weapon( void )
{
	std::cout << "Weapon " << this->_type << " deleted" << std::endl;
	return;
}

std::string const	&Weapon::getType( void )
{
	return (this->_type);
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}
