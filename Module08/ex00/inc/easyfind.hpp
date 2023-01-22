/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:45:40 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/22 23:00:05 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <exception>
# include <list>
# include <vector>

# define RED(s) "\033[1;31m" s "\033[m"
# define GREEN(s) "\033[1;32m" s "\033[m"
# define BLUE(s) "\033[1;34m" s "\033[m"

class NoOccurenceFoundException : public std::exception
{
	public:
		virtual const char	*what( void ) const throw()
		{
			return (RED("RESULT : No occurence is found"));
		}
};

template< typename T >
typename T::const_iterator	easyfind(T &t, int search)
{
	typename T::const_iterator	post;
	
	post = find(t.begin(), t.end(), search);
	if (post == t.end())
		throw NoOccurenceFoundException();
		
	return (post);
}

#endif
