/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:18:13 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/15 17:41:01 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ): Animal("Dog")
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->_brain = new Brain();
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
	this->_brain = new Brain( *rhs._brain);
	return (*this);
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
	return;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Waf Waf !" << std::endl;
}
