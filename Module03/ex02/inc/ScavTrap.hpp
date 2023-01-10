/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:09:11 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 17:17:33 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( const std::string name );
		ScavTrap( ScavTrap const &src );
		
		virtual ~ScavTrap( void );

		ScavTrap	&operator=( ScavTrap const &rhs );
	
		void		attack( const std::string &target );
		void		guardGate( void );
};

std::ostream	&operator<<( std::ostream &obj, ScavTrap const &insert );

#endif
