/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:38:44 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/19 23:03:37 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>

# define RED(s) "\033[1;31m" s "\033[m"
# define GREEN(s) "\033[1;32m" s "\033[m"

template< typename T >
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array( void ) : _size( 0 )
		{
			this->_array = new T[this->_size];
			return ;
		}
		
		Array( unsigned int n ) : _size( n )
		{
			this->_array = new T[this->_size];
			return ;
		}
		
		Array( Array const &src )
		{
			*this = src;
			return ;
		}
		
		~Array( void )
		{
			if (this->_array)
				delete [] this->_array;
			return ;
		}
		
		Array	&operator=( Array const &rhs )
		{
			if (this != &rhs)
			{
			// 	if (this->_array)
			// 		delete [] this->_array;
				this->_size = rhs.size();
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = rhs._array[i];
			}
			return (*this);
		}

		T	&operator[]( unsigned int i )
		{
			if (i >= this->_size || !this->_array)
			{
				std::cerr << RED("ERROR : ");
				throw Array<T>::OutOfBondsException();
			}
			return (this->_array[i]);
		}

		unsigned int	size( void ) const
		{
			return (this->_size);
		}

		class OutOfBondsException : public std::exception
		{
			public:
				virtual const char	*what( void ) const throw()
				{
					return (RED("Index is out of bond"));
				}
		};
};

#endif
