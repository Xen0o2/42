/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:29:21 by alecoutr          #+#    #+#             */
/*   Updated: 2023/09/28 15:49:11 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


Form::Form( void ): _name("default"), _gradeRequiredForSignature(150), _gradeRequiredForExecution(150)
{
    this->_isSigned = false;
    std::cout << "Form default constructor called" << std::endl;
    return;
}

Form::Form( int gradeRequiredForSignature, int gradeRequiredForExecution ): _name("default"), _gradeRequiredForSignature(gradeRequiredForSignature), _gradeRequiredForExecution(gradeRequiredForExecution)
{
    this->_isSigned = false;
    std::cout << "Form string constructor called" << std::endl;
    return;
}

Form::Form( std::string name, int gradeRequiredForSignature, int gradeRequiredForExecution ): _name(name), _gradeRequiredForSignature(gradeRequiredForSignature), _gradeRequiredForExecution(gradeRequiredForExecution)
{
    this->_isSigned = false;
    std::cout << "Form string constructor called" << std::endl;
    return;
}

Form::Form( Form const &copy ): _name(copy.getName()), _gradeRequiredForSignature(copy.getGradeRequiredForSignature()), _gradeRequiredForExecution(copy.getGradeRequiredForExecution())
{
    std::cout << "Form copy constructor called" << std::endl;
    return;
}

Form    &Form::operator=( Form const &rhs )
{
    this->_isSigned = rhs._isSigned;   
    std::cout << "Form assignment operator called" << std::endl;
    return (*this);
}

Form::~Form( void )
{
    std::cout << "Form destructor called" << std::endl;
    return;
}

std::string Form::getName( void ) const
{
    return (this->_name);
}



std::string    Form::getIsSigned( void )
{
    if (this->_isSigned)
        return ("Signed");
    else
        return ("Not signed");
}

bool    Form::getIsSignedBool( void ) const
{
    return (this->_isSigned);
}

void    Form::beSigned( Bureaucrat &bureaucrat )
{
    std::cout << bureaucrat.getName() << " bureaucrat is trying to sign " << this->_name << " Form" << std::endl;
    if (this->_isSigned)
        std::cout << "Form already signed" << std::endl;
    else if (bureaucrat.getGrade() <= this->_gradeRequiredForSignature)
    {
        this->_isSigned = 1;
        std::cout << this->_name << " form signed by " << bureaucrat.getName() << " bureaucrat" << std::endl;
    }
    else
        throw (Bureaucrat::GradeTooLowException());
}

int     Form::getGradeRequiredForSignature( void ) const
{
    return (this->_gradeRequiredForSignature);
}

int     Form::getGradeRequiredForExecution( void ) const
{
    return (this->_gradeRequiredForExecution);
}

void Form::execute( Bureaucrat const &executor ) const
{
    if (executor.getGrade() > this->_gradeRequiredForExecution)
        throw Bureaucrat::GradeTooLowException();
    else if (!this->getIsSignedBool())
        throw Form::FormNotSignedException();
    else
    {
        std::cout << executor.getName() << " executed Form : " << this->_name << std::endl;
        this->beExecuted(executor);
    }
}

Form    *Form::makeForm( std::string const &type, std::string const &target )
{
    Form    *form;

    form = NULL;
    form = PresidentialPardonForm::makeForm(form, type, target);
    form = RobotomyRequestForm::makeForm(form, type, target);
    form = ShrubberyCreationForm::makeForm(form, type, target);
    return (form);   
}

const char *Form::GradeTooHighException::what( void ) const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what( void ) const throw()
{
    return ("Grade is too Low");
}

const char *Form::FormNotSignedException::what( void ) const throw()
{
    return ("Form must be signed before execution");
}

const char  *Form::InvalidFormException::what( void ) const throw()
{
    return ("Invalid Form type");
}

std::ostream &operator<<( std::ostream &o, Form *a )
{
    o << "Form " << a->getName() << " :" << std::endl <<
         "Grade required for signature : " << a->getGradeRequiredForSignature() << std::endl <<
         "Grade required for execution : " << a->getGradeRequiredForExecution() << std::endl <<
         "Status : " << a->getIsSigned() << std::endl;
    return (o);
}
