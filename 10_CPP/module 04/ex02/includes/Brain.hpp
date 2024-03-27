/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:19:17 by alecoutr          #+#    #+#             */
/*   Updated: 2023/06/15 17:56:31 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain( void );
		Brain( Brain const &copy);
		Brain	&operator=( Brain const &rhs );
		virtual ~Brain( void );

};

#endif
