/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:53:34 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 23:53:16 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice( void );
		Ice( Ice const &src );

		virtual ~Ice( void );
		
		Ice					&operator=( Ice const &rhs );

		virtual AMateria	*clone( void ) const;
		virtual void		use( ICharacter &target );
};

#endif
