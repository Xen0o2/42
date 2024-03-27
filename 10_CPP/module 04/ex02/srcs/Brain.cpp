/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:18:13 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/15 17:36:04 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Default Brain constructor called" << std::endl;
	return;
}

Brain::Brain( Brain const &copy )
{
	std::cout << "Copy Brain constructor called" << std::endl;
	*this = copy;
	return;
}

Brain	&Brain::operator=( Brain const &rhs )
{
	for(int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	std::cout << "Assignment Brain operator called" << std::endl;
	return (*this);
}

Brain::~Brain( void )
{
	std::cout << "Brain destructor called" << std::endl;
	return;
}
