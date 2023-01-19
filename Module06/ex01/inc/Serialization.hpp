/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:22:51 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/19 12:15:20 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <stdint.h>

# define GREEN(s) "\033[1;32m" s "\033[m"

typedef struct Data
{
	std::string	str;
	int			i;
	size_t		len;
	Data		*next;
	Data		*prev;
}				Data;

class	Serialization
{
	public:
		Serialization( void );
		Serialization( Serialization const &src );

		~Serialization( void );

		Serialization	&operator=( Serialization const &rhs );
		
		uintptr_t		serialize( Data *ptr );
		Data			*deserialize( uintptr_t raw );
	
};

#endif
