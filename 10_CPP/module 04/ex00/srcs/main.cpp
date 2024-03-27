/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:29:12 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 22:10:05 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int	main( void )
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	const WrongAnimal* x = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << x->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	x->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
	delete x;

	return (0);
}
