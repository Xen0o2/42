/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:53:42 by alecoutr          #+#    #+#             */
/*   Updated: 2023/09/28 14:46:27 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>

class Bureaucrat
{
	private:
		std::string const _name;
		int			_grade;
	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const &copy );
		Bureaucrat	&operator=( Bureaucrat const &rhs );
		~Bureaucrat( void );

		std::string getName( void );
		int	getGrade( void );

		void increaseGrade( void );
		void decreaseGrade( void );
		void setGrade( int const grade );

		

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

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif
