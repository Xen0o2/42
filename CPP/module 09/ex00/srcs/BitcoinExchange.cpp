/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:01:03 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/10 10:54:33 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
	std::cout << "Default constructor called" << std::endl;

	std::ifstream file ("./data.csv");
	if (!file.is_open())
		throw BitcoinExchange::cantOpenDataException();
	
	std::string line;
	int			i = 1;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		int index = line.find(',');
		if (index == -1)
		{
			std::cerr << "Invalid parameter at line " << i << std::endl;
			continue;
		}
		std::string date = line.substr(0, index);
		float		value;

		try
		{
			value = std::stod(line.substr(index + 1));
		}
		catch(std::exception &e)
		{
			std::cerr << "Couldn't parse value at line " << (i + 1) << std::endl;
			continue;
		}
		this->setData(date, value);
		i++;
	}
	file.close();
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return;
}

BitcoinExchange	&BitcoinExchange::operator=( BitcoinExchange const &rhs )
{
	std::cout << "Assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_data = rhs._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void )
{
	std::cout << "Destructor called" << std::endl;
}

std::map<std::string, float>	BitcoinExchange::getData( void )
{
	return (this->_data);
}

void	BitcoinExchange::setData( std::string date, float value )
{
	this->_data.insert(std::make_pair(date, value));
}

std::vector<std::string>	BitcoinExchange::split( std::string line )
{
	std::vector<std::string>	result;
	std::string					tmp = "";

	for(size_t i = 0; i < line.length(); i++)
	{
		if (line[i] != '|')
			tmp += line[i];
		else if (tmp.length() != 0)
		{
			result.push_back(tmp);
			tmp = "";
		}
	}
	
	result.push_back(tmp);
	return (result);
}

void	BitcoinExchange::readInput( std::string path )
{
	std::ifstream file (path);
	if (!file.is_open())
		throw BitcoinExchange::cantOpenInputException();

	std::string 				line;
	std::vector<std::string>	lineVector;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		lineVector = this->split(line);
		if (lineVector.size() != 2)
		{
			std::cout << "Error: bad input => " << lineVector[0] << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it = this->_data.upper_bound(lineVector[0]);
		if (it != this->_data.end())
		{
			std::pair<std::string, float> pair = *(--it);
			try
			{
				if (std::stof(lineVector[1]) > 1000)
					std::cout << "Error: too large a number." << std::endl;
				else if(std::stof(lineVector[1]) < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else
					std::cout << lineVector[0] << "=>" << lineVector[1] << " = " << (std::stof(lineVector[1]) * pair.second) << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "Error: Input is not a number (" << e.what() << ")" << std::endl;
				continue;
			}
		}
	}
}
