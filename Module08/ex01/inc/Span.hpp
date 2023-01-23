/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:45:40 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/23 13:42:30 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <exception>
# include <vector>

# define RED(s) "\033[1;31m" s "\033[m"
# define GREEN(s) "\033[1;32m" s "\033[m"
# define BLUE(s) "\033[1;34m" s "\033[m"

class Span
{
	private:
		std::vector<int>	_vct;
		unsigned int		_max;
			
		Span( void );

	public:
		Span( unsigned int N );
		Span( Span const &src );

		~Span( void );

		Span					&operator=( Span const &rhs );

		unsigned int			getMax( void ) const;
		std::vector<int> const	&getVct( void ) const;
		
		void					addNumber( int nb );
		void					addNumber( std::vector<int>::const_iterator first, std::vector<int>::const_iterator last );
		unsigned int			shortestSpan(void ) const;
		unsigned int			longestSpan( void ) const;

		class reachedMaxCapacityException : public std::exception
		{
			virtual const char	*what( void ) const throw();
		};

		class noSpanFound : public std::exception
		{
			virtual const char	*what( void ) const throw();
		};
};

std::ostream	&operator<<( std::ostream &obj, Span const &insert );

#endif
