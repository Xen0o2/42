/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:59:04 by alecoutr          #+#    #+#             */
/*   Updated: 2023/09/28 15:15:32 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const	_name;
        bool				_isSigned;
        int const			_gradeRequiredForSignature;
		int const			_gradeRequiredForExecution;
    public:
        Form( void );
		Form( int gradeRequiredForSignature, int gradeRequiredForExecution );
        Form( std::string name, int gradeRequiredForSignature, int gradeRequiredForExecution );
        Form( Form const &copy );
        Form( &operator=( Form const & rhs ));
        ~Form( void );

		std::string getName( void ) const;
		std::string	getIsSigned( void );
		bool		getIsSignedBool( void );
		void		beSigned( Bureaucrat &bureaucrat );
		int			getGradeRequiredForExecution( void ) const;
		int			getGradeRequiredForSignature( void ) const;
		
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
};

std::ostream	&operator<<(std::ostream &o, Form *a);
