/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:37:47 by alecoutr          #+#    #+#             */
/*   Updated: 2023/09/28 15:46:31 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <stdlib.h>

class RobotomyRequestForm: public Form
{
    private:
        RobotomyRequestForm( void );
        std::string _target;
    public:
        RobotomyRequestForm( std::string target );
        RobotomyRequestForm( RobotomyRequestForm const &copy );
        RobotomyRequestForm &operator=( RobotomyRequestForm const &rhs );
        ~RobotomyRequestForm( void );
        
        std::string getTarget( void ) const;
        void    beExecuted( Bureaucrat const &executor ) const;
        static Form    *makeForm( Form *form, std::string const &type, std::string const &target );
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm &form);
