/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:21:58 by alecoutr          #+#    #+#             */
/*   Updated: 2023/09/28 14:50:31 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void )
{
	this->_grade = 1;
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat( std::string name, int grade): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
	std::cout << "Bureaucrat string constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat( Bureaucrat const &copy )
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
	return;
}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &rhs )
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return;
}

std::string	Bureaucrat::getName( void )
{
	return (this->_name);
}

int	Bureaucrat::getGrade( void )
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade( void )
{
	try
	{
		std::cout << "Trying to increase " << this->_name << "'s grade" << std::endl;
		this->setGrade(this->_grade - 1);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Increasing " << this->_name << " failed: " << e.what() << std::endl;
	}
}

void	Bureaucrat::decreaseGrade( void )
{
	try
	{
		std::cout << "Trying to decrease " << this->_name << "'s grade" << std::endl;
		this->setGrade(this->_grade + 1);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Decreasing " << this->_name << " failed: " << e.what() << std::endl;
	}
}

void	Bureaucrat::setGrade( int const grade )
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

const char	*Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high !");
}


const char	*Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade too low !");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << " is currently grade " << a->getGrade() << std::endl;
	return (o);
}

