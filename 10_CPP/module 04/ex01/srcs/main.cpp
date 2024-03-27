/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:29:12 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/15 17:57:36 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main( void )
{

	int	size = 2;
	Animal *animals[size];

	for(int i = 0; i < size; i++)
	{
		if (i < size / 2)	
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for(int i = 0; i < size; i++)
		delete animals[i];

	return (0);
}
