/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:53:30 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/11 02:04:09 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];
		int			_slot;
	
	public:
		Character( void );
		Character( std::string name );
		Character( Character const &src );
		
		virtual ~Character( void );

		Character					&operator=( Character const &rhs );
		
		virtual std::string const	&getName( void ) const;
		virtual void				equip( AMateria *m );
		virtual void				unequip(int idx );
		virtual void				use( int idx, ICharacter& target );
};

#endif
