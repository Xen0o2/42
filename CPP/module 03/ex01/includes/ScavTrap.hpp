/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:33:49 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 02:20:48 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		bool	_GuardingGate;
		
	public:
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const &src);
		ScavTrap	&operator=( ScavTrap const &rhs );
		virtual ~ScavTrap( void );

		void	attack( std::string const &target );
		void	guardGate( void );
};

#endif
