/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 08:37:54 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/08 09:40:36 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ): _N(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Span::Span( unsigned int N ): _N(N)
{
	std::cout << "N constructor called with value : " << N << std::endl;
	this->_vector.reserve(N);
	return;
}

Span::Span( Span const &copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
}

Span	&Span::operator=( Span const &rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	
	this->_N = rhs._N;
	return (*this);
}

Span::~Span( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Span::addNumber( int number )
{
	if (this->_vector.size() == this->_N)
		throw Span::VectorFullException();
	this->_vector.push_back(number);
}

void	Span::addNumbers( int range, bool isRandom )
{
	for(int i = 0; i < range; i++)
	{
		try
		{
			addNumber(isRandom ? rand() % range : i);	
		}
		catch (Span::VectorFullException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}	
}

int		Span::shortestSpan( void )
{
	if (this->_vector.empty())
		throw Span::VectorEmptyException();
	else if (this->_vector.size() == 1)
		throw Span::VectorIsOneException();
	else
	{
		std::vector<int> copy = this->_vector;
		std::sort(copy.begin(), copy.end());

		std::vector<int>::iterator it = copy.begin();
		std::vector<int>::iterator itnext = copy.begin() + 1;
		int tmp = __INT_MAX__;
		
		while (itnext != copy.end())
		{
			if ((*itnext - *it) < tmp)
				tmp = *itnext - *it;
			it++;
			itnext++;
		}
		return (tmp);
	}
}

int		Span::longestSpan( void )
{
	if (this->_vector.empty())
		throw Span::VectorEmptyException();
	else if (this->_vector.size() == 1)
		throw Span::VectorIsOneException();
	else
	{
		std::vector<int> copy = this->_vector;
		std::sort(copy.begin(), copy.end());
		return (copy[copy.size() - 1] - copy[0]);
	}	
}
