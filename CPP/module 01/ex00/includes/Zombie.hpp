/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:52:11 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 11:56:59 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string.h>
# include <iostream>

class	Zombie 
{
	public:
		Zombie( std::string name );
		~Zombie( void );
		
		void	announce( void );
  
	private:
		std::string	_name;
};

Zombie	*newZombie( std::string name);
void	randomChump( std::string name );

#endif
