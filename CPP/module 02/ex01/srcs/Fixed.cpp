/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:00:19 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 20:30:32 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed( void ): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( int const value ): _value(value * pow(2, this->_bits))
{
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed( float const value ): _value(value * pow(2, this->_bits))
{
	std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}


int	Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (this->_value * pow(2, -this->_bits));
}

int		Fixed::toInt( void ) const
{
 	return (this->_value * pow(2, -this->_bits));
}

std::ostream	&operator<<( std::ostream &o, Fixed const &i)
{
	return (o << i.toFloat());
}
