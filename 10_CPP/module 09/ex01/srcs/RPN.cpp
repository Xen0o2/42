/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:01:03 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/12 07:59:53 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void )
{
	return;
}

RPN::RPN( RPN const &copy )
{
	*this = copy;
	return;
}

RPN	&RPN::operator=( RPN const &rhs )
{
	if (this != &rhs)
		return (*this);
	this->_numbers = rhs._numbers;
	return (*this);
}

RPN::~RPN( void )
{
	return;
}

void	RPN::calculate( std::string expression )
{
	for(size_t i = 0; i < expression.length(); i++)
	{
		char c = expression[i];

		if (c == ' ' || c == '\t' || c == '\n')
			continue;
		else if (std::isdigit(c))
		{
			int number = c - '0';
			this->_numbers.push(number);
		}
		else if (this->_numbers.size() >= 2)
		{
			double a = this->_numbers.top();
			this->_numbers.pop();
			double b = this->_numbers.top();
			this->_numbers.pop();
			switch (c)
			{
				case '+':
					this->_numbers.push(b + a);
					break;
				case '-':
					this->_numbers.push(b - a);
					break;
				case '*':
					this->_numbers.push(b * a);
					break;
				case '/':
					this->_numbers.push(b / a);
					break;
				default:
					std::cout << "Error: Invalid input" << std::endl;
					return;
			}
		}			
	}
	if (this->_numbers.size() == 1)
	{
		double	result = this->_numbers.top();
		this->_numbers.pop();
		std::cout << result << std::endl;
	}
	else
		std::cout << "Error: Invalid input" << std::endl;
}
