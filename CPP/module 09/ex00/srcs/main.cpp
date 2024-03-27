/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:11:10 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/10 10:29:03 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int ac, char **av )
{
	if (ac != 2)
		return ( std::cerr << "Usage: " << av[0] << " <path>" << std::endl, 1);
	BitcoinExchange btc;

	btc.readInput(av[1]);
}
