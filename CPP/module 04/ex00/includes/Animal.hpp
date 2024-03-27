/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:15:51 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 22:07:32 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string.h>
# include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal( void );
		Animal( std::string type );
		Animal( Animal const &copy );
		Animal	&operator=( Animal const &rhs );
		virtual ~Animal( void );

		virtual void makeSound( void ) const;
		std::string getType( void ) const;
};


#endif
