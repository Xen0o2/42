/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:51:43 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/05 13:06:32 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

typedef struct s_Data
{
	int	value;
}	t_Data;


class Serializer
{
	public:
		Serializer( void );
		Serializer( Serializer const &copy );
		Serializer	&operator=( Serializer const &rhs );
		~Serializer( void );

		uintptr_t serialize( t_Data *ptr );
		t_Data	*deserialize( uintptr_t raw );
};

#endif
