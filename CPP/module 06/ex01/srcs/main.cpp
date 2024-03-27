/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:04:04 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/05 13:09:53 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main( void )
{
	t_Data* data;
	uintptr_t rawData;
	t_Data* retData;
	Serializer serializer;

	data = new t_Data;

	std::cout << "Data             : " << data << std::endl;
	rawData = serializer.serialize(data);
	std::cout << "Raw data         : " << rawData << std::endl;
	retData = serializer.deserialize(rawData);
	std::cout << "Deserialized data: " << retData << std::endl;

	delete data;	
}
