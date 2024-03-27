/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:00:19 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 20:54:42 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed( void ): _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( int const value ): _value(value * pow(2, this->_bits))
{
	//std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed( float const value ): _value(value * pow(2, this->_bits))
{
	//std::cout << "Float constructor called" << std::endl;
	return;
}

Fixed::~Fixed( void )
{
	//std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}


int	Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits function called" << std::endl;
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

bool	Fixed::operator>( Fixed const &rhs ) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<( Fixed const &rhs ) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator>=( Fixed const &rhs ) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator<=( Fixed const &rhs ) const
{
	return (this->toFloat() <= rhs.toFloat());
}

Fixed	Fixed::operator+( Fixed const &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-( Fixed const &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*( Fixed const &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/( Fixed const &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++( void )
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--( void )
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++( int value )
{
	Fixed i(*this);

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return (i);
}

Fixed	Fixed::operator--( int value )
{
	Fixed i(*this);

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return (i);
}

Fixed const	&Fixed::min( Fixed &a, Fixed &b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed const	&Fixed::min( Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed const	&Fixed::max( Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max( Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

