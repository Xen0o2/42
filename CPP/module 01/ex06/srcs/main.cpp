/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:31:55 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 18:11:04 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int		level_to_int( std::string level )
{
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	for(int i = 0; i < 4; i++)
		if (level == levels[i])
			return (i);
	return (-1);
}

void	harl_switch(std::string level, Harl &harl)
{
	switch (level_to_int(level))
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

int	main( int ac, char **av )
{
	Harl harl;
	
	if (ac != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		harl_switch(av[1], harl);
	return (0);	
}
