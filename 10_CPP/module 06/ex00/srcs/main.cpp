/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:04:04 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/05 12:27:18 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main( int ac, char **av )
{

	if (ac == 2)
	{
		ScalarConverter converter;
		converter.convert(av[1]);
	}
	else
		std::cout << "Nothing to convert" << std::endl;
}
