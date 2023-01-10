/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:30 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 21:04:52 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <cerrno>
# include <cstring>
# include <cstdlib>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal( void );
		Animal( const std::string type );
		Animal( Animal const &src );
		
		virtual ~Animal( void );

		Animal			&operator=( Animal const &rhs );

		std::string		getType( void ) const;	
		
		virtual void	makeSound( void ) const;
};

#endif
