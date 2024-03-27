/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:04:04 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/05 13:49:48 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "classes.hpp"

Base::~Base( void ) {};

Base	*generate( void )
{
	std::srand(time(NULL));
	int	i = rand() % 3;

	switch (i)
	{
		case 0:
			std::cout << "Generate class A" << std::endl;
			return (new A);
		case 1:
			std::cout << "Generate class B" << std::endl;
			return (new B);
		case 2:
			std::cout << "Generate class C" << std::endl;
			return (new C);
		break;
	}
	
	std::cout << "An error happened, can't generate a class" << std::endl;
	return (NULL);
}

void	identify( Base	*p )
{
	if (dynamic_cast<A*>(p))
		std::cout << "A class was identified" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B class was identified" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C class was identified" << std::endl;
	else
		std::cout << "An error happened, class can't be identified" << std::endl;
}

void	identify( Base &p )
{
	try
	{
		A a = dynamic_cast<A&>(p);(void)a;
		std::cout << "A class was identified" << std::endl;
		return;
	}
	catch(std::exception &e) {}
	
	try
	{
		B b = dynamic_cast<B&>(p);(void)b;
		std::cout << "B class was identified" << std::endl;
		return;
	}
	catch(std::exception &e) {}
	
	try
	{
		C c = dynamic_cast<C&>(p);(void)c;
		std::cout << "C class was identified" << std::endl;
		return;
	}
	catch(std::exception &e) {}
	
	std::cout << "An error happened, class can't be identified" << std::endl;	
}


int main( void )
{
	Base	*p = generate();

	identify(p);
	identify(*p);
	
}
