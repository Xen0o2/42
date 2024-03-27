/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:33:47 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 02:31:22 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name): ClapTrap(name)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	this->_GuardingGate = false;
	std::cout << "ScavTrap default constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap( ScavTrap const &src ): ClapTrap(src)
{
	this->_GuardingGate = src._GuardingGate;
	std::cout << "ScavTrap copy constructor called" << std::endl;
	return;
}

ScavTrap	&ScavTrap::operator=( ScavTrap const &rhs )
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	this->_Name = rhs._Name;
	this->_HitPoints = rhs._HitPoints;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return;
}

void	ScavTrap::attack( std::string const &target)
{
	if (this->_EnergyPoints > 0 && this->_HitPoints > 0)
	{
		std::cout << "ScavTrap " << this->_Name << " attacks " << target << " causing " << this->_AttackDamage << " points of damage" << std::endl;
		this->_EnergyPoints--; 
	}
	else
	{
		if (this->_EnergyPoints == 0)
			std::cout << "ScavTrap " << this->_Name << " can't attack " << target << " because he has not energy points left" << std::endl;
		else
			std::cout << "ScavTrap " << this->_Name << " can't attack " << target << " because he has no more hit points" << std::endl;
	}
}

void	ScavTrap::guardGate( void )
{
	if (this->_GuardingGate)
		std::cout << "ScavTrap " << this->_Name << " is already keeping the gate" << std::endl;
	else
		std::cout << "ScavTrap " << this->_Name << " is now keeping the gate" << std::endl;
	this->_GuardingGate = true;
}
