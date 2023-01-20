/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:38:44 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/20 15:56:38 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template< typename T >
void	swap( T &x, T &y )
{
	T	tmp;
	
	tmp = x;
	x = y;
	y = tmp;
}

template< typename T >
T const	&min( T const &x, T const &y )
{
	return (x <= y ? x : y);
}

template< typename T >
T const	&max( T const &x, T const &y )
{
	return (x >= y ? x : y);
}

class Awesome
{
	public:
		Awesome( void ) : _n(0) {}
		Awesome( int n ) : _n(n) {}
		
		Awesome	&operator=( Awesome &a ) { _n = a._n; return *this; }
		
		bool	operator==( Awesome const &rhs ) const { return (this->_n == rhs._n); }
		bool	operator!=( Awesome const &rhs ) const { return (this->_n != rhs._n); }
		bool	operator>( Awesome const &rhs ) const { return (this->_n > rhs._n); }
		bool	operator<( Awesome const &rhs ) const { return (this->_n < rhs._n); }
		bool	operator>=( Awesome const &rhs ) const { return (this->_n >= rhs._n); }
		bool	operator<=( Awesome const &rhs ) const { return (this->_n <= rhs._n); }
		int		get_n( void ) const { return _n; }
		
	private:
		int	_n;
		
};

std::ostream	&operator<<( std::ostream &o, const Awesome &a )
{
	o << a.get_n();
	return o;
}

#endif
