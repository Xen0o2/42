/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:11:10 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/12 07:50:09 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int ac, char **av )
{
	if (ac != 2)
		return ( std::cerr << "Usage: " << av[0] << " <Inverted Polish Mathematical Expression>" << std::endl, 1);
	RPN rpn;

	rpn.calculate(av[1]);
}
