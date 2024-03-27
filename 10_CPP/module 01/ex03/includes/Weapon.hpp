/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:01:21 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 15:23:43 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string.h>
# include <iostream>

class	Weapon
{
	private:
		std::string	_type;

	public:
		Weapon( std::string type );
		~Weapon( void );
		std::string const	&getType( void );
		void				setType(std::string type);
};

#endif
