/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:59:04 by alecoutr          #+#    #+#             */
/*   Updated: 2023/09/28 15:47:59 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

#define SHRUBERRY_SIGNATURE 145
#define SHRUBERRY_EXECUTION 137
#define ROBOTOMY_SIGNATURE 72
#define ROBOTOMY_EXECUTION 45
#define PRESIDENTIAL_SIGNATURE 25
#define PRESIDENTIAL_EXECUTION 5

class Bureaucrat;

class Form
{
    protected:
        std::string const _name;
        bool			_isSigned;
        int const		_gradeRequiredForSignature;
		int	const		_gradeRequiredForExecution;
        Form( void );
        Form( int gradeRequiredForSignature, int gradeRequiredForExecution );
        Form( std::string name, int gradeRequiredForSignature, int gradeRequiredForExecution );
        Form( Form const &copy );
    public:
        Form &operator=( Form const &rhs );
        virtual ~Form( void );

		std::string getName( void ) const;
		std::string	getIsSigned( void );
		bool	getIsSignedBool( void ) const;
		void	beSigned( Bureaucrat &bureaucrat );
		int		getGradeRequiredForSignature( void ) const;
		int		getGradeRequiredForExecution( void ) const;
		void	execute( Bureaucrat const &executor ) const;
		virtual void beExecuted( Bureaucrat const &executor ) const = 0; 
		static Form	*makeForm( std::string const &type, std::string const &target );
		
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};

		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char 	*what( void ) const throw();
		};

		class InvalidFormException: public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Form *a);
