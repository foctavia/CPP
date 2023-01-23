/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:45:40 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/23 10:52:14 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// source : https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators#comment109978849_49001896

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <stack>

# define RED(s) "\033[1;31m" s "\033[m"
# define GREEN(s) "\033[1;32m" s "\033[m"
# define BLUE(s) "\033[1;34m" s "\033[m"

template< class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack( void ) : std::stack<T, Container>() {}
		MutantStack( MutantStack const &src ) : std::stack<T, Container>( src ) {}

		~MutantStack( void ) {}
		
		MutantStack	&operator=( MutantStack const &rhs )
		{
			if (this != &rhs)
				std::stack<T, Container>::operator=(rhs);
			return (*this);
		}

		typedef typename std::stack<T, Container>::container_type::const_iterator	iterator;

		iterator	begin( void ) const { return this->c.begin(); }
		iterator	end( void ) const { return this->c.end(); }
};

#endif
