/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:53:31 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 21:11:45 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap()
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std::cout << "FragTrap default constructor for " << this->_Name << " called" << std::endl;
	return;
}

FragTrap::FragTrap( std::string name ): ClapTrap(name)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap( FragTrap const &src ): ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	return;
}

FragTrap	&FragTrap::operator=( FragTrap const &rhs )
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	this->_Name = rhs._Name;
	this->_HitPoints = rhs._HitPoints;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called" << std::endl;
	return;
}

void	FragTrap::highFiveGuys ( void )
{
	std::cout << "Is there someone for a high five ?" << std::endl;
	return;
}
