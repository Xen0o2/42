/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:07:10 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 15:22:37 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB( std::string name );
		~HumanB();
		void	attack( void );
		void	setWeapon( Weapon &weapon );

};

#endif
