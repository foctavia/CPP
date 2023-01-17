/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:53:47 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/17 11:48:53 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name( "unknown" ), _slot( 0 ), _floorIdx( 0 )
{
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for(int i = 0; i < 10; i++)
		this->_floor[i] = NULL;
	return ;
}

Character::Character( std::string name ) : _name( name ), _slot( 0 ), _floorIdx( 0 )
{
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for(int i = 0; i < 10; i++)
		this->_floor[i] = NULL;
	return ;
}

Character::Character( Character const &src )
{
	*this = src;
	return ;
}

Character::~Character( void )
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	for(int i = 0; i < 10; i++)
	{
		if (this->_floor[i])
			delete this->_floor[i];
	}
	return ;
}

Character	&Character::operator=( Character const &rhs )
{
	if (this == &rhs)
	{
		for(int i = 0; i < 4; i++)
			this->_inventory[i] = rhs._inventory[i];
		for(int i = 0; i < 10; i++)
			this->_floor[i] = rhs._floor[i];
		this->_name = rhs.getName();
		this->_slot = rhs._slot;
		this->_floorIdx = rhs._floorIdx;
	}
	return (*this);
}

std::string const	&Character::getName( void ) const
{
	return (this->_name);
}

void	Character::equip( AMateria* m )
{
	if (!m || this->_slot >= 4)
		return ;
	int	i = 0;
	while (this->_inventory[i])
		i++;
	this->_inventory[i] = m;
	this->_slot++;
}

void	Character::unequip(int idx )
{
	if (idx < 0 || idx >= 4)
		return ;
	if (this->_inventory[idx])
	{
		if (this->_floorIdx >= 10)
		{
			delete this->_floor[0];
			for (int i = 0; i < 9; i++)
				this->_floor[i] = this->_floor[i + 1];
			this->_floorIdx--;
		}
		this->_floor[_floorIdx] = this->_inventory[idx];
		this->_inventory[idx] = NULL;
		this->_floorIdx++;
	}
	this->_slot--;
}

void	Character::use( int idx, ICharacter& target )
{
	if (idx < 0 || idx >= 4)
		return ;
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}