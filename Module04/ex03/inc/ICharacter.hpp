/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:53:36 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/11 01:43:11 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter( void ) {}
		
		virtual std::string const	&getName( void ) const = 0;
		virtual void 				equip( AMateria *m ) = 0;
		virtual void 				unequip(int idx ) = 0;
		virtual void 				use( int idx, ICharacter& target ) = 0;
};

#endif
