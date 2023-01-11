/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:53:41 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/11 01:43:53 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materias[4];
	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const &src );
		
		virtual ~MateriaSource( void );

		MateriaSource		&operator=( MateriaSource const &rhs );
		
		virtual void 		learnMateria( AMateria* );
		virtual AMateria	*createMateria( std::string const &type );
};

#endif

