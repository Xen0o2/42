/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 06:50:17 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/04 07:17:23 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern( void );	
		Intern( Intern const &copy );
		Intern	&operator=( Intern const & rhs );
		~Intern( void );

		Form	*makeForm( std::string const &type, std::string const &target );
};
