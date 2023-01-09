/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:30:47 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 12:36:18 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_HPP
# define DIAMOND_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap( void );
		DiamondTrap( const std::string name );
		DiamondTrap( DiamondTrap const &src );
		
		virtual ~DiamondTrap( void );

		DiamondTrap	&operator=( DiamondTrap const &rhs );

		void		attack( const std::string &target );
		void		whoAmI( void );
};

std::ostream	&operator<<( std::ostream &obj, DiamondTrap const &insert );

#endif