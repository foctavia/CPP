/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:33 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 23:59:53 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat( void );
		Cat( Cat const &src );

		virtual ~Cat( void );

		Cat	&operator=( Cat const &rhs );

		virtual void	makeSound( void ) const;
};

#endif
