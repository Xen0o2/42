/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:18:13 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 21:52:03 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ): Animal("Dog")
{
	std::cout << "Default Dog constructor called" << std::endl;
	return;
}

Dog::Dog( Dog const &copy ): Animal(copy)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = copy;
	return;
}

Dog	&Dog::operator=( Dog const &rhs )
{
	std::cout << "Assignment Dog operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called" << std::endl;
	return;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Waf Waf !" << std::endl;
}
