/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:39:05 by alecoutr          #+#    #+#             */
/*   Updated: 2023/07/07 10:07:13 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T	*_array;
		unsigned int	_size;
	public:
		Array( void ): _size(0)
		{
			std::cout << "Default constructor called: empty array created" << std::endl;	
			this->_array = new T[this->_size];
		}
		Array( unsigned int n ): _size(n)
		{
			std::cout << "N constructor called: empty array of size " << n << " created" << std::endl;
			this->_array = new T[this->_size];	
		}
		Array( Array const &copy ): _size(copy.size())
		{
			std::cout << "Copy constructor called" << std::endl;
			this->_array = NULL;
			*this = copy;
		}

		~Array( void )
		{
			std::cout << "destructor called" << std::endl;
			if (this->_array != NULL)
				delete [] this->_array;
		}		
		
		Array	&operator=( Array const &src )
		{
			std::cout << "Assignment operator called" << std::endl;
			if (this->_array != NULL)
				delete [] this->_array;
			if (src.size() != 0)
			{
				this->_size = src.size();
				this->_array = new T[src.size()];
				for(unsigned int i = 0; i < src.size(); i++)
					this->_array[i] = src._array[i];
			}
			return (*this);
		}

		T	&operator[]( unsigned int index )
		{
			if (index >= this->_size || this->_array == NULL)
				throw (Array<T>::InvalidIndexException());
			return (this->_array[index]);
		}

		unsigned int	size( void ) const
		{
			return (this->_size);
		}

		class InvalidIndexException: public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("Invalid index");
			}
		};

};

#endif
