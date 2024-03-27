/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:18:13 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 22:04:16 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ): WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	return;
}

WrongCat::WrongCat( WrongCat const &copy ): WrongAnimal(copy)
{
	std::cout << "Copy WrongCat constructor called" << std::endl;
	*this = copy;
	return;
}

WrongCat	&WrongCat::operator=( WrongCat const &rhs )
{
	std::cout << "Assignment WrongCat operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destructor called" << std::endl;
	return;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Meowwwww !" << std::endl;
}
