/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:18:13 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 22:02:22 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal( std::string type ): _type(type)
{
	std::cout << "Default WrongAnimal of type " << type << " constructor called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal( WrongAnimal const &copy )
{
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
	*this = copy;
	return;
}

WrongAnimal	&WrongAnimal::operator=( WrongAnimal const &rhs )
{
	std::cout << "Assignment WrongAnimal operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal destructor called" << std::endl;
	return;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "* Some animal noises *" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->_type);
}
