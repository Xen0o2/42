/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:58:27 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 20:43:03 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_value;
		static int const	_bits;
public:
		Fixed( void );
		Fixed( int const value);
		Fixed( float const value);
		Fixed( Fixed const &src );
		~Fixed();

		Fixed	&operator=( Fixed const &rhs );
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		bool	operator>( Fixed const &rhs ) const ;
		bool	operator<( Fixed const &rhs ) const ;
		bool	operator>=( Fixed const &rhs ) const ;
		bool	operator<=( Fixed const &rhs ) const ;
		bool	operator==( Fixed const &rhs ) const ;
		bool	operator!=( Fixed const &rhs ) const ;

		Fixed	operator+( Fixed const &rhs ) const ;
		Fixed	operator-( Fixed const &rhs ) const ;
		Fixed	operator*( Fixed const &rhs ) const ;
		Fixed	operator/( Fixed const &rhs ) const ;

		Fixed	&operator++( void );
		Fixed	&operator--( void );
		Fixed	operator++( int value );
		Fixed	operator--( int value );

		static Fixed const	&min( Fixed &a, Fixed &b);
		static Fixed const	&min( Fixed const &a, Fixed const &b);
		static Fixed const	&max( Fixed &a, Fixed &b);
		static Fixed const	&max( Fixed const &a, Fixed const &b);
};

std::ostream	&operator<<( std::ostream &o, Fixed const &i);

#endif
