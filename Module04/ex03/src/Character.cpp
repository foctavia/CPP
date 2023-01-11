/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:53:47 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/11 01:58:32 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name( "unknown" ), _slotIdx( 0 )
{
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character( std::string name ) : _name( name ), _slotIdx( 0 )
{
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character( Character const &src )
{
	*this = src;
	return ;
}

Character::~Character( void )
{
	return ;
}

Character	&Character::operator=( Character const &rhs )
{
	if (this == &rhs)
	{
		for(int i = 0; i < 4; i++)
			this->_inventory[i] = rhs._inventory[i];
		this->_name = rhs.getName();
		this->_slotIdx = rhs._slotIdx;
	}
	return (*this);
}

std::string const	&Character::getName( void ) const
{
	return (this->_name);
}

void	Character::equip( AMateria* m )
{
	if (!m || _slotIdx >= 4)
		return ;
	int	i = 0;
	while (this->_inventory[i])
		i++;
	this->_inventory[i] = m;
	this->_slotIdx++;
}

void	Character::unequip(int idx )
{
	if (idx < 0 || idx >= 4)
		return ;
	if (this->_inventory[idx])
		this->_inventory[idx] = NULL;
	this->_slotIdx--;
}

void	Character::use( int idx, ICharacter& target )
{
	if (idx < 0 || idx >= 4)
		return ;
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}