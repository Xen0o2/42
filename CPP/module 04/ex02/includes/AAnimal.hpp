/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:15:51 by alecoutr          #+#    #+#             */
/*   Updated: 2023/08/21 09:57:07 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

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

		virtual void makeSound( void ) const = 0;
		std::string getType( void ) const;
};


#endif
