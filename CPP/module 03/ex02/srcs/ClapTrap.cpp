/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:47:16 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 02:06:24 by alecoutr         ###   ########.fr       */
/*                                                                             */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ): _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap const &src )
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	return;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap destructor called" << std::endl;
	return;
}

ClapTrap &ClapTrap::operator=( ClapTrap const &rhs )
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	this->_Name = rhs._Name;
	this->_HitPoints = rhs._HitPoints;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;

	return (*this);
}

void	ClapTrap::attack( std::string const &target )
{
	if (this->_EnergyPoints > 0 && this->_HitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_Name << " attacks " << target << " causing " << this->_AttackDamage << " points of damage" << std::endl;
		this->_EnergyPoints--; 
	}
	else
	{
		if (this->_EnergyPoints == 0)
			std::cout << "ClapTrap " << this->_Name << " can't attack " << target << " because he has not energy points left" << std::endl;
		else
			std::cout << "ClapTrap " << this->_Name << " can't attack " << target << " because he has no more hit points" << std::endl;
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_HitPoints > amount)
	{
		this->_HitPoints -= amount;
		std::cout << "ClapTrap " << this->_Name << " was attacked and lost " << amount << " hit points, he now has " << this->_HitPoints << " hit points" << std::endl;
	}
	else if (this->_HitPoints == amount)
	{
		this->_HitPoints = 0;
		std::cout << "ClapTrap " << this->_Name << " was attacked and lost " << amount << " hit points, he just died" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_Name << " is already dead, stop beating it" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_EnergyPoints > 0 && this->_HitPoints > 0 && this->_HitPoints + amount <= 10)
	{
		this->_HitPoints += amount;
		this->_EnergyPoints--;
		std::cout << "ClapTrap " << this->_Name << " repaired himself and gain " << amount << " hit points, he now has " << this->_HitPoints << " hit points" << std::endl;
	}
	else if (this->_EnergyPoints == 0)
		std::cout << "ClapTrap " << this->_Name << " can't repair himself, he has no energy point left" << std::endl;
	else if (this->_HitPoints == 0)
		std::cout << "ClapTrap " << this->_Name << " can't repair himself, just because he is dead" << std::endl;
	else if (this->_HitPoints == 10)
		std::cout << "ClapTrap " << this->_Name << " is already full of hit points" << std::endl;
	else if (this->_HitPoints + amount > 10)
		std::cout << "ClapTrap " << this->_Name << " can't have more than 10 hit points" << std::endl;
}
