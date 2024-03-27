/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 06:54:05 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/04 07:43:36 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
	std::cout << "Intern default constructor called" << std::endl;
	return;
}

Intern::Intern( Intern const &copy )
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
	return;
}

Intern	&Intern::operator=( Intern const &rhs )
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

Intern::~Intern( void )
{
	std::cout << "Intern destructor called" << std::endl;	
	return;
}

Form	*Intern::makeForm( std::string const &type, std::string const &target )
{
	Form	*form;

	form = Form::makeForm(type, target);
	if (!form)
		throw Form::InvalidFormException();
	else
		std::cout << "Intern creates " << form->getName() << " with target " << target << std::endl;
	return (form);
}
