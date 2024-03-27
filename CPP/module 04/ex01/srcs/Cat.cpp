/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:18:13 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/15 17:38:48 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ): Animal("Cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->_brain = new Brain();
	return;
}

Cat::Cat( Cat const &copy ): Animal(copy)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = copy;
	return;
}

Cat	&Cat::operator=( Cat const &rhs )
{
	std::cout << "Assignment Cat operator called" << std::endl;
	this->_type = rhs._type;
	this->_brain = new Brain( *rhs._brain);
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
	return;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meowwwww !" << std::endl;
}
