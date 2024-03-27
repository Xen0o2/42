/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:15:51 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/14 22:06:07 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat( void );
		Cat( Cat const &copy );
		Cat	&operator=( Cat const &rhs );
		~Cat( void );

		virtual void	makeSound( void ) const;
};

#endif
