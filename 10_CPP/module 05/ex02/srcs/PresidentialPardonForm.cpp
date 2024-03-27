/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:29:21 by alecoutr          #+#    #+#             */
/*   Updated: 2023/09/28 15:25:09 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): Form("PresidentialPardonForm", PRESIDENTIAL_SIGNATURE, PRESIDENTIAL_EXECUTION), _target("default")
{ 
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): Form("PresidentialPardonForm", PRESIDENTIAL_SIGNATURE, PRESIDENTIAL_EXECUTION), _target(target)
{
    std::cout << "PresidentialPardonForm string constructor for target " << target << " called" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &copy ): Form("PresidentialPardonForm", copy.getGradeRequiredForSignature(), copy.getGradeRequiredForExecution()), _target(copy._target)
{
    *this = copy;
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    return;
}

PresidentialPardonForm    &PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs )
{
    Form::operator=(rhs);
	this->_target = rhs._target;
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
    std::cout << "PresidentialPardonForm " << this->getName() << " destructor called" << std::endl;
    return;
}

std::string PresidentialPardonForm::getTarget( void ) const
{
    return (this->_target);
}

void    PresidentialPardonForm::beExecuted( Bureaucrat const &executor ) const
{
    (void)executor;
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<( std::ostream &o, PresidentialPardonForm *form )
{
    o << "PresidentialPardonForm " << form->getName() << " :" << std::endl <<
         "Grade required for signature : " << form->getGradeRequiredForSignature() << std::endl <<
         "Grade required for execution : " << form->getGradeRequiredForExecution() << std::endl <<
         "Status : " << form->getIsSigned() << std::endl;
    return (o);
}
