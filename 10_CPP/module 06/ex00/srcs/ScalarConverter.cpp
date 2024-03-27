/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:41:53 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/05 12:42:45 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
	return;
}

ScalarConverter::ScalarConverter( ScalarConverter const &copy )
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = copy;
	return;
}

ScalarConverter	&ScalarConverter::operator=( ScalarConverter const &rhs )
{
	std::cout << "ScalarConverter assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);

	return (*this);
}

ScalarConverter::~ScalarConverter( void )
{
	std::cout << "ScalarConverter destructor called" << std::endl;
	return;
}

void	ScalarConverter::convert( std::string const &literal )
{
	std::string	specialTypes[6] = { "-inff", "+inff", "nanf", "-inf", "+inf", "nan" };

	std::string	toChar = "";
	long long int			toInt = 0;
	float		toFloat = 0;
	double		toDouble = 0;

	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		toChar = literal[0];
		std::cout << "char   : " << toChar << std::endl <<
					 "int    : " << static_cast<int>(literal[0]) << std::endl <<
					 "float  : " << static_cast<float>(literal[0]) << std::endl <<
					 "double : " << static_cast<double>(literal[0]) << std::endl;
		return;
	}

	for (int i = 0; i < 6; i++)
	{
		if (literal == specialTypes[i])
		{
			toChar = "Impossible";
			break;
		}
	}

	toInt = std::atoll(literal.c_str());
		
	if (literal[literal.size() - 1] == 'f')
	{
		toFloat = std::atof(literal.c_str());
		toDouble = static_cast<double>(toFloat);
	}
	else
	{
		toDouble = std::atof(literal.c_str());
		toFloat = static_cast<float>(toDouble);
	}

	if (toChar == "" && std::isprint(toInt))
	{
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";

	}
	else if (toChar == "")
		toChar = "Non displayable";
	
	std::cout << "char   : " << toChar << std::endl;

	if (toChar == "Impossible" || toInt > INT_MAX)
		std::cout << "int    : Impossible" << std::endl;
	else
		std::cout << "int    : " << toInt << std::endl;

	if (toChar == "Impossible" && toFloat == 0)
	{
		std::cout << "float  : Impossible" << std::endl <<
					 "double : Impossible" << std::endl;
	}
	else
	{
		if (toChar != "Impossible" && toFloat - static_cast<int>(toFloat) == 0) 
		{
			std::cout << "float  : " << toFloat << ".0f" << std::endl;
			std::cout << "double : " << toDouble << ".0" << std::endl;
		} 
		else 
		{
			std::cout << "float  : " << toFloat << "f" << std::endl;
			std::cout << "double : " << toDouble << std::endl;
		}
	}
}
