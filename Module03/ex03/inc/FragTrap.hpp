/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:46:47 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 17:17:59 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( const std::string name );
		FragTrap( FragTrap const &src );
		
		virtual ~FragTrap( void );

		FragTrap	&operator=( FragTrap const &rhs );

		void		highFivesGuys( void );
};

std::ostream	&operator<<( std::ostream &obj, FragTrap const &insert );

#endif
