/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:33 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 18:32:34 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;
	
	public:
		Cat( void );
		Cat( Cat const &src );

		virtual ~Cat( void );

		Cat					&operator=( Cat const &rhs );

		virtual void		makeSound( void ) const;
		
		const std::string	getIdeas( size_t i ) const;
		void				setIdeas( size_t i, std::string idea );
};

#endif
