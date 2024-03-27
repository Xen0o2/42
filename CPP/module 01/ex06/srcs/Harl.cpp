/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:07:20 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 17:34:40 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
	std::cout << "New Harl has been created" << std::endl;
	return;
}

Harl::~Harl( void )
{
	std::cout << "A Harl has been destroyed" << std::endl;
	return;
}

void	Harl::_debug( void )
{
	std::cout << "[DEBUG]" << std::endl 
			  << "I love having extra bacon for my"
			  << "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void	Harl::_info( void )
{
	std::cout << "[INFO]" << std::endl 
			  << "I cannot believe adding extra bacon costs more money. You didn’t put"
			  << "enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::_warning( void )
{
	std::cout << "[WARNING]" << std::endl 
			  << "I think I deserve to have some extra bacon for free. I’ve been coming"
			  << "for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error( void )
{
	std::cout << "[ERROR]" << std::endl 
			  << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	void	(Harl::*choicePtr[4])( void ) = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	
	for(int i = 0; i < 4; i++)
		if (level == levels[i])
			(this->*choicePtr[i])();	
}
