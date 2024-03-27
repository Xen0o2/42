/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:18:13 by alecoutr          #+#    #+#             */
/*   Updated: 2023/08/21 09:56:46 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

Animal::Animal( void )
{
	std::cout << "Default Animal constructor called" << std::endl;
	return;
}

Animal::Animal( std::string type ): _type(type)
{
	std::cout << "Default Animal of type " << type << " constructor called" << std::endl;
	return;
}

Animal::Animal( Animal const &copy )
{
	std::cout << "Copy Animal constructor called" << std::endl;
	*this = copy;
	return;
}

Animal	&Animal::operator=( Animal const &rhs )
{
	std::cout << "Assignment Animal operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

Animal::~Animal( void )
{
	std::cout << "Animal destructor called" << std::endl;
	return;
}

void	Animal::makeSound( void ) const
{
	std::cout << "* Some animal noises *" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return (this->_type);
}
