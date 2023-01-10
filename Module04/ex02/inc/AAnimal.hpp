/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:35:30 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 21:20:40 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
# include <cerrno>
# include <cstring>
# include <cstdlib>

class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal( void );
		AAnimal( const std::string type );
		AAnimal( AAnimal const &src );
		
		virtual ~AAnimal( void );

		AAnimal			&operator=( AAnimal const &rhs );

		std::string		getType( void ) const;	
		
		virtual void	makeSound( void ) const = 0;
};

#endif
