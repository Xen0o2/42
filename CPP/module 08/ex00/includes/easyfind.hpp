/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:20:48 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/07 18:34:10 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <vector>
# include <iostream>

class NotFoundException: public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("Occurence not found");
		}
};

template <typename T>
int	*easyfind(T &a, int b)
{
	typename T::iterator it = std::find(a.begin(), a.end(), b);

	if (it == a.end())
		throw NotFoundException();
	return (&(*it));
}

#endif