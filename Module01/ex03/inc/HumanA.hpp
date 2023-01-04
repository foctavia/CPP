/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:22:21 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/04 22:32:27 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;
	
	public:
		HumanA( std::string name, Weapon &weapon);
		~HumanA( void );
		
		void	attack( void );
};

#endif
