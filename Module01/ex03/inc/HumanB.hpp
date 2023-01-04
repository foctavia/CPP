/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:22:24 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/04 22:53:40 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon;
	
	public:
		HumanB( std::string name );
		~HumanB( void );
		
		void	attack( void );
		void	setWeapon( Weapon &weapon );
};

#endif