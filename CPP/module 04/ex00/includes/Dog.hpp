/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:15:51 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 22:06:05 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog( void );
		Dog( Dog const &copy );
		Dog	&operator=( Dog const &rhs );
		~Dog( void );

		virtual void	makeSound( void ) const;
};

#endif
