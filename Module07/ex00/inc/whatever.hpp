/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:38:44 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/19 17:05:55 by foctavia         ###   ########.fr       */
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

#endif
