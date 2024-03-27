/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:29:21 by alecoutr          #+#    #+#             */
/*   Updated: 2023/09/28 15:17:17 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ): _name("default"), _gradeRequiredForSignature(150), _gradeRequiredForExecution(150)
{
    _isSigned = false;
    std::cout << "Form default constructor called" << std::endl;
    return;
}

Form::Form( int gradeRequiredForSignature, int gradeRequiredForExecution): _name("default"), _gradeRequiredForSignature(gradeRequiredForSignature), _gradeRequiredForExecution(gradeRequiredForExecution)
{
    if (gradeRequiredForSignature > 150 || gradeRequiredForExecution > 150)
        throw Form::GradeTooLowException();
    else if (gradeRequiredForSignature < 1 || gradeRequiredForExecution < 1)
        throw Form::GradeTooHighException();
    _isSigned = false;
    std::cout << "Form string constructor called" << std::endl;
    return;
}

Form::Form( std::string name, int gradeRequiredForSignature, int gradeRequiredForExecution): _name(name), _gradeRequiredForSignature(gradeRequiredForSignature), _gradeRequiredForExecution(gradeRequiredForExecution)
{
    if (gradeRequiredForSignature > 150 || gradeRequiredForExecution > 150)
        throw Form::GradeTooLowException();
    else if (gradeRequiredForSignature < 1 || gradeRequiredForExecution < 1)
        throw Form::GradeTooHighException();
    _isSigned = false;
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
    _isSigned = rhs._isSigned;   
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
    return (_name);
}



std::string    Form::getIsSigned( void )
{
    if (_isSigned)
        return ("Signed");
    else
        return ("Not signed");
}

bool    Form::getIsSignedBool( void )
{
    return (_isSigned);
}

void    Form::beSigned( Bureaucrat &bureaucrat )
{
    std::cout << bureaucrat.getName() << " bureaucrat is trying to sign " << _name << " Form" << std::endl;
    if (_isSigned)
        std::cout << "Form already signed" << std::endl;
    else if (bureaucrat.getGrade() <= _gradeRequiredForSignature)
    {
        _isSigned = 1;
        std::cout << _name << " form signed by " << bureaucrat.getName() << " bureaucrat" << std::endl;
    }
    else
        throw Form::GradeTooLowException();
}

int	Form::getGradeRequiredForSignature( void ) const
{
    return (_gradeRequiredForSignature);
}

int Form::getGradeRequiredForExecution( void ) const
{
    return (_gradeRequiredForExecution);
}

const char *Form::GradeTooHighException::what( void ) const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what( void ) const throw()
{
    return ("Grade is too Low");
}

std::ostream &operator<<( std::ostream &o, Form *a )
{
    o << "Form " << a->getName() << " :" << std::endl <<
         "Grade required for signature : " << a->getGradeRequiredForSignature() << std::endl <<
         "Grade required for execution : " << a->getGradeRequiredForExecution() << std::endl <<
         "Status : " << a->getIsSigned() << std::endl;
    return (o);
}
