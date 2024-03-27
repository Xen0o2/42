/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:18:13 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 21:52:06 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ): Animal("Cat")
{
	std::cout << "Default Cat constructor called" << std::endl;
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
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called" << std::endl;
	return;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meowwwww !" << std::endl;
}
