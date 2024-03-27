/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:52:11 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/13 11:57:22 by alecoutr         ###   ########.fr       */
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
		Zombie( void );
		~Zombie( void );
		
		void		announce( void );
		void		setName( std::string name );
		std::string	getName( void );
	private:
		std::string	_name;
};

Zombie	*newZombie( std::string name);
void	randomChump( std::string name );
Zombie	*zombieHorde( int N, std::string name);

#endif
