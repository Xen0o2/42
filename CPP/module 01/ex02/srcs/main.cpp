/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:05:19 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 12:54:30 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int	main( void )
{
	std::string hiSentence = "HI THIS IS BRAIN";
	std::string	*stringPTR = &hiSentence;
	std::string	&stringREF = hiSentence;

	std::cout << "Adresse de la string           : " << &hiSentence << std::endl
			  << "Adresse stockée dans stringPTR : " << stringPTR << std::endl
			  << "Adresse stockée dans stringREF : " << &stringREF << std::endl << std::endl
			  << "Valeur de la string            : " << hiSentence << std::endl
			  << "Valeur pointée par stringPTR   : " << *stringPTR << std::endl
			  << "Valeur pointée par stringREF   : " << stringREF << std::endl;
}
