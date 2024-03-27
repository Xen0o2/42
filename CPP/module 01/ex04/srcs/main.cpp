/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:09:05 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 17:01:07 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

int	main(int ac, char **av)
{
	(void)ac;
	if (ac != 4)
		return (std::cout << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl, 0);

	std::string		filename = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::ifstream	inFileDescriptor (filename);
	
	if (!inFileDescriptor)
		return (std::cout << filename << ": No such file" << std::endl, 1);
	
	std::string			fileContent;
	char				c;
	
	while (!inFileDescriptor.eof() && inFileDescriptor >> std::noskipws >> c)
		fileContent += c;
	inFileDescriptor.close();

	int	index;
	std::ofstream	outFileDescriptor (filename + ".replace");
	
	if (!outFileDescriptor)
		return (std::cout << "File cannot be created" << std::endl, 1);

	for(int i = 0; i < (int)fileContent.length(); i++)
	{
		index = fileContent.find(s1, i);
		if (index == i)
		{
			outFileDescriptor << s2 << std::flush;
			i += s1.length() - 1;
		}
		else
			outFileDescriptor << fileContent[i];
	}
	outFileDescriptor.close();
	return (0);
}
