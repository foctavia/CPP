/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:09:17 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 10:57:16 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( const std::string name ) : ClapTrap( name )
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const &src ) : ClapTrap(src)
{
	std::cout << "ScavTrap " << this->_name << " copy constructor called" << std::endl;
	return ;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator=( ScavTrap const &rhs )
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}
	std::cout << "ScavTrap " << this->_name << " assignment operator called" << std::endl;
	return (*this);
}

void	ScavTrap::attack( const std::string &target )
{
	if (this->_energyPoint > 0 && this->_hitPoint > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoint--;
	}
	else if (this->_hitPoint <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack " << target
			<< ", because he is dead." << std::endl;
	}
	else if (this->_energyPoint <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " failed to attack " << target
			<< ", because he does not have enough energy left." << std::endl;
	}
}

void	ScavTrap::guardGate( void )
{
	if (this->_hitPoint > 0)
		std::cout << "ScavTrap " << this->_name << " is guarding the gate." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " cannot guarding the gate, because he is dead." << std::endl;
}

std::ostream	&operator<<( std::ostream &obj, ScavTrap const &insert )
{
	obj << "_name: " << insert.getName() << std::endl
		<< "_hitPoint: " << insert.getHitPoint() << std::endl
		<< "_energyPoint: " << insert.getEnergyPoint() << std::endl
		<< "_attackDamage: " << insert.getAttackDamage() << std::endl;
	return (obj);
}
