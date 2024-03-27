/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:57:35 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/11 11:40:28 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	put_length(std::string string)
{
	if (string.size() > 10)
	{
		string.resize(9);
		string += ".";
		std::cout << string;
	}
	else
		std::cout << string;
}

int	main( void )
{
	std::string command;
	PhoneBook phonebook;

	while (command != "EXIT")
	{
		std::cout << "Commande : ";
		getline(std::cin, command);
		if (command == "ADD")
		phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		
		if (std::cin.eof())
			return (std::cout << std::endl << "^D cliqué, arrêt en cours..." << std::endl, 0);
	}
}
