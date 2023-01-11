/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:09:09 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/11 18:01:56 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hitPoint;
		int			_energyPoint;
		int			_attackDamage;
		
	public:
		ClapTrap( void );
		ClapTrap( const std::string name );
		ClapTrap( ClapTrap const &src );

		virtual ~ClapTrap( void );
		
		ClapTrap	&operator=( ClapTrap const &rhs );

		std::string	getName( void ) const;	
		int			getHitPoint( void ) const;
		int			getEnergyPoint( void ) const;
		int			getAttackDamage( void ) const;

		void		attack( const std::string &target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );
};

std::ostream	&operator<<( std::ostream &obj, ClapTrap const &insert );

#endif
