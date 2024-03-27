/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:58:27 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 20:06:02 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static int const	_bits;
public:
		Fixed( void );
		Fixed( Fixed const &src );
		~Fixed();

		Fixed	&operator=( Fixed const &rhs );
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
};


#endif
