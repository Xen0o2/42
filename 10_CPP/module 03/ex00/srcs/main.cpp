/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:17:19 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 02:25:31 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap bot ("Bot");

	bot.attack("Dustin");
	bot.takeDamage(8);
	bot.beRepaired(1);
	bot.beRepaired(1);
	bot.beRepaired(1);
	bot.beRepaired(1);
	bot.beRepaired(1);
	bot.beRepaired(1);
	bot.beRepaired(1);
	bot.beRepaired(2);
	bot.beRepaired(1);
	bot.beRepaired(1);
	bot.takeDamage(5);
	bot.beRepaired(1);
	bot.beRepaired(1);
	bot.takeDamage(6);
	bot.takeDamage(1);
	
}
