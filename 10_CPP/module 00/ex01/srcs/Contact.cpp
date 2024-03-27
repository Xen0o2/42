/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:11:54 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/11 11:25:17 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact( void )
{
    return;
}

Contact::~Contact( void )
{
    return;
}

void Contact::display(int index)
{
    std::cout << std::setw(10);
    std::cout << index + 1 << " | ";
    std::cout << std::setw(10);
    put_length(this->_firstname);
    std::cout << " | " << std::setw(10);
    put_length(this->_lastname);
    std::cout << " | " << std::setw(10);
    put_length(this->_nickname);
    std::cout << std::endl;
}

void	Contact::showInformation( void )
{
	std::cout << "Prénom : " << this->_firstname << std::endl;
	std::cout << "Nom : " << this->_lastname << std::endl;
	std::cout << "Surnom : " << this->_nickname << std::endl;
	std::cout << "Numéro de téléphone : " << this->_phoneNumber << std::endl;
	std::cout << "Secret le plus lourd : " << this->_darkestSecret << std::endl << std::endl;
}

std::string Contact::getFirstname( void )
{
    return (this->_firstname);
}

void        Contact::setFirstname( std::string firstname )
{
    this->_firstname = firstname;
}

std::string Contact::getLastname( void )
{
    return (this->_lastname);
}

void        Contact::setLastname( std::string lastname )
{
    this->_lastname = lastname;
}

std::string Contact::getNickname( void )
{
    return (this->_nickname);
}

void        Contact::setNickname( std::string nickname )
{
    this->_nickname = nickname;
}

std::string Contact::getPhoneNumber( void )
{
    return (this->_phoneNumber);
}

void        Contact::setPhoneNumber( std::string phoneNumber )
{
    this->_phoneNumber = phoneNumber;
}

std::string Contact::getDarkestSecret( void )
{
    return (this->_darkestSecret);
}

void        Contact::setDarkestSecret( std::string darkestSecret )
{
    this->_darkestSecret = darkestSecret;
}
