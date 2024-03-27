/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:22:47 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/08 09:41:33 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	int size = 50;
	Span span = Span(size);

	for(int i = 0; i < size / 2; i++)
		span.addNumber( rand() % size );
		//span.addNumber( i );
	
	span.addNumbers(size / 2, false);
	
	try
	{
		span.addNumber( 100 );
	}
	catch( Span::VectorFullException &e )
	{
		std::cerr << "Can't add more number because : " << e.what() << std::endl;
	}

	std::cout << "Shortest span is : " << span.shortestSpan() << std::endl;
	std::cout << "Longest span is : " << span.longestSpan() << std::endl;

	return (0);
}
