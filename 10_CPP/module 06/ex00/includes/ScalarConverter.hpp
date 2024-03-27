/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:17:01 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/05 12:24:40 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>

# define CHAR   1
# define INT    2
# define FLOAT  3
# define DOUBLE 4

class ScalarConverter
{
	public:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const &copy );
		ScalarConverter	&operator=( ScalarConverter const &rhs );
		~ScalarConverter( void );

		static void	convert( std::string const &literal );
};

#endif
