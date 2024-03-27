/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:22:47 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/07 18:28:05 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	int	* find;
	std::vector<int> arr;

	try
	{
		arr.push_back(10);
		arr.push_back(20);
		find = easyfind(arr, 20);
		std::cout << "Found number " << *find << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<int> arr2(10, -1);
		find = easyfind(arr2, 3);
		std::cout << "Found number " << *find << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
