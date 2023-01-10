/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:35 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 20:48:55 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;
	
	public:
		Dog( void );
		Dog( Dog const &src );

		virtual ~Dog( void );

		Dog					&operator=( Dog const &rhs );

		virtual void		makeSound( void ) const;

		const std::string	getIdeas( size_t i ) const;
		void				setIdeas( size_t i, std::string idea );
};

#endif
