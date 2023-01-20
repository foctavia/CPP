/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:38:44 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/20 16:02:27 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>
# include <cctype>

template< typename T >
void	iter( T *array, size_t len, void (*func)(T &))
{
	if (!array || !func)
		return ;
	for (size_t	i = 0; i < len; i++)
		func(array[i]);
}

template< typename T >
void	print( T &t )
{
	std::cout << t;
}

class Awesome
{
	public:
		Awesome( void ) : _n(42) {}
		
		int	get( void ) const { return this->_n; }

	private:
		int _n;	
};

std::ostream	&operator<<( std::ostream &o, Awesome const &rhs )
{
	o << rhs.get();
	return o;
}

#endif
