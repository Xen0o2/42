/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:58:27 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 20:21:30 by alecoutr         ###   ########.fr       */
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
};

std::ostream	&operator<<( std::ostream &o, Fixed const &i);

#endif
