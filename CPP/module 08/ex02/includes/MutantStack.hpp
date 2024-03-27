/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 08:36:11 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/08 10:11:56 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack( void ){};
		MutantStack( MutantStack const &copy ): std::stack<T>(copy){};
		MutantStack	&operator=( MutantStack const &rhs )
		{
			if (this == &rhs)
				return (*this);
			this->c = rhs.c;
			return (*this);
		};
		
		~MutantStack( void )
		{
			this->c.clear();
		};
		

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin( void )
		{
			return (this->c.begin());
		};
		iterator	end( void )
		{
			return (this->c.end());
		};

};

#endif
