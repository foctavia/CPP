/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:09:15 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 12:30:23 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name( "random_guy" ), _hitPoint( 10 ), _energyPoint( 10 ), _attackDamage( 0 )
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( const std::string name ) : _name( name ), _hitPoint( 10 ), _energyPoint( 10 ), _attackDamage( 0 )
{
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const &src )
{
	*this = src;
	std::cout << "ClapTrap " << this->_name << " copy constructor called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=( ClapTrap const &rhs )
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}
	std::cout << "ClapTrap " << this->_name << " assignment operator called" << std::endl;
	return (*this);
}

std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoint( void ) const
{
	return (this->_hitPoint);
}

unsigned int	ClapTrap::getEnergyPoint( void ) const
{
	return (this->_energyPoint);
}

unsigned int	ClapTrap::getAttackDamage( void ) const
{
	return (this->_attackDamage);
}

void	ClapTrap::attack( const std::string &target )
{
	if (this->_energyPoint > 0 && this->_hitPoint > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoint--;
	}
	else if (this->_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack " << target
			<< ", because he is dead." << std::endl;
	}
	else if (this->_energyPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " failed to attack " << target
			<< ", because he does not have enough energy left." << std::endl;
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoint > 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! ";
		this->_hitPoint -= amount;
		if (this->_hitPoint < 0)
			this->_hitPoint = 0;
		std::cout << "He now has " << this->_hitPoint << " hit points left." << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is already dead. He cannot take anymore damage!" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_energyPoint > 0 && this->_hitPoint > 0)
	{
		std::cout << "ClapTrap " << this->_name << " gains " << amount << " hit points! ";
		this->_hitPoint += amount;
		std::cout << "He now has " << this->_hitPoint << " hit points." << std::endl;
		this->_energyPoint--;
	}
	else if (this->_hitPoint <= 0)
		std::cout << "ClapTrap " << this->_name << " cannot be repaired, because he is dead." << std::endl;
	else if (this->_energyPoint <= 0)
		std::cout << "ClapTrap " << this->_name << " failed to repair itself, because it does not have enough energy left." << std::endl;
}

std::ostream	&operator<<( std::ostream &obj, ClapTrap const &insert )
{
	obj << "_name: " << insert.getName() << std::endl
		<< "_hitPoint: " << insert.getHitPoint() << std::endl
		<< "_energyPoint: " << insert.getEnergyPoint() << std::endl
		<< "_attackDamage: " << insert.getAttackDamage() << std::endl;
	return (obj);
}
