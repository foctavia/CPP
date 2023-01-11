/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:53:32 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/11 01:45:19 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure( void );
		Cure( Cure const &src );

		virtual ~Cure( void );
		
		Cure				&operator=( Cure const &rhs );

		virtual AMateria	*clone( void ) const;
		virtual void		use( ICharacter &target );
		
};

#endif
