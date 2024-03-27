/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:11:10 by alecoutr          #+#    #+#             */
/*   Updated: 2023/10/27 18:14:35 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char* av[])
{
	if (ac <= 1)
    {
        std::cerr << "Error: No input sequence provided." << std::endl;
        return 1;
    }
	PmergeMe pmergeMe(ac, av);
	(void)pmergeMe;
    return 0;
}
