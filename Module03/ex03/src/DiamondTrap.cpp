/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:30:53 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 12:40:43 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap()
{
	this->_name = ClapTrap::_name;
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDamage = FragTrap::_attackDamage;
	this->ClapTrap::_name = this->_name + "_clap_name";
	std::cout << "DiamondTrap default constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap( const std::string name ) : ClapTrap( name + "_clap_name"), _name( name )
{
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const &src ) 
	: ClapTrap( src._name + "_clap_name" )
	, ScavTrap( src._name + "_clap_name" )
	, FragTrap( src._name + "_clap_name" )
{
	*this = src;
	std::cout << "DiamondTrap " << this->_name << " copy constructor called" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=( DiamondTrap const &rhs )
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}
	this->ClapTrap::_name = rhs._name + "_clap_name";
	std::cout << "DiamondTrap " << this->_name << " assignment operator called" << std::endl;
	return (*this);
}

void	DiamondTrap::attack( const std::string &target )
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap " << this->_name
		<< " is a ClapTrap " << ClapTrap::_name << " monster which is half FragTrap and half ScavTrap."
		<< std::endl;
}

std::ostream	&operator<<( std::ostream &obj, DiamondTrap const &insert )
{
	obj << "_name: " << insert.getName() << std::endl
		<< "_hitPoint: " << insert.getHitPoint() << std::endl
		<< "_energyPoint: " << insert.getEnergyPoint() << std::endl
		<< "_attackDamage: " << insert.getAttackDamage() << std::endl;
	return (obj);
}
