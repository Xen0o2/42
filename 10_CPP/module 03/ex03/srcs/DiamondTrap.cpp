/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:39:06 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/15 15:48:47 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name): ClapTrap(name + "_clap_name")
{
	this->_Name = name;
	this->_HitPoints = FragTrap::_HitPoints;
	this->_EnergyPoints = ScavTrap::_EnergyPoints;
	this->_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
	return;
}

DiamondTrap::DiamondTrap( DiamondTrap const &copy ): ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=( DiamondTrap const &rhs )
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	this->_Name = rhs._Name + "_clap_name";
	this->_HitPoints = rhs._HitPoints;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called" << std::endl;
	return;
}

void	DiamondTrap::attack ( std::string const &target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "I am DiamondTrap named " << this->_Name
			  << " and I'm from the ClapTrap " << ClapTrap::_Name << std::endl;
}
