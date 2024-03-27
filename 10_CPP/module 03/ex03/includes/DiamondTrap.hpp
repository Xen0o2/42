/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:06:59 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 21:08:13 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string	_Name;

	public:
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const &copy );
		DiamondTrap	&operator=( DiamondTrap const &rhs );
		virtual ~DiamondTrap( void );

		void	attack( std::string const &target );
		void	whoAmI( void );
};

#endif
