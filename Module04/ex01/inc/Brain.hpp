/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:42:03 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 19:19:21 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain
{
	private:
		std::string	_ideas[100];
		
	public:
		Brain( void );
		Brain( const Brain &src );

		~Brain( void );

		Brain				&operator=( Brain const &rhs );
		
		const std::string	getIdeas( size_t i ) const;
		void				setIdeas( size_t i, std::string idea );
};

#endif
