/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:22:19 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/04 22:44:38 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string	_type;
		
	public:
		Weapon( const std::string type );
		~Weapon( void );

		std::string	getType( void ) const;
		void		setType( const std::string &type );
};

#endif
