/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:22:57 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/19 11:44:30 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization( void )
{
	return ;
}

Serialization::Serialization( Serialization const &src )
{
	*this = src;
	return ;
}

Serialization::~Serialization( void )
{
	return ;
}

Serialization	&Serialization::operator=( Serialization const &rhs )
{
	(void)rhs;
	return (*this);
}

uintptr_t	Serialization::serialize( Data *ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serialization::deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data *>(raw));
}
