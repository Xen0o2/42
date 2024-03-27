/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:45:18 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 21:12:00 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string.h>

class ClapTrap
{
	protected:
		std::string		_Name;
		unsigned int	_HitPoints;
		unsigned int	_EnergyPoints;
		unsigned int	_AttackDamage;
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const &src);
		ClapTrap	&operator=( ClapTrap const &rhs );
		~ClapTrap( void );


		void	attack( std::string const &target );
		void	takeDamage( unsigned int amount);
		void	beRepaired( unsigned int amount);
};

#endif
