/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:15:51 by alecoutr          #+#    #+#             */
/*   Updated: 2023/08/21 09:56:56 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog( void );
		Dog( Dog const &copy );
		Dog	&operator=( Dog const &rhs );
		~Dog( void );

		virtual void	makeSound( void ) const;
};

#endif
