/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:53:28 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/17 10:16:37 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include <cerrno>
# include <cstring>
# include <cstdlib>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	_type;
	
	public:
		AMateria( void );
		AMateria( std::string const &type );
		AMateria( AMateria const &src );

		virtual ~AMateria( void );

		AMateria			&operator=( AMateria const &rhs );

		std::string const	&getType( void ) const; //Returns the materia type
		
		virtual AMateria	*clone( void ) const = 0;
		virtual void 		use( ICharacter &target );
};

#endif
