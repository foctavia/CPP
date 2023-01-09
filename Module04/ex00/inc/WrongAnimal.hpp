/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:00:38 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 00:31:35 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal( void );
		WrongAnimal( const std::string type );
		WrongAnimal( WrongAnimal const &src );
		
		virtual ~WrongAnimal( void );

		WrongAnimal	&operator=( WrongAnimal const &rhs );

		std::string	getType( void ) const;	
		void		makeSound( void ) const;
};

#endif
