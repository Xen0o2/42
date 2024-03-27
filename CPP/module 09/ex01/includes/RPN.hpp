/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 07:26:01 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/12 07:50:31 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
	private:
		std::stack<double>	_numbers;
	public:
		RPN( void );
		RPN( RPN const &copy );
		RPN	&operator=(RPN const &rhs );
		~RPN( void );
		
		void	calculate( std::string expression );		
};

#endif
