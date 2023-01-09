/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:46:36 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 11:09:52 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap( const std::string name ) : ClapTrap( name )
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap( FragTrap const &src ) : ClapTrap(src)
{
	std::cout << "FragTrap " << this->_name << " copy constructor called" << std::endl;
	return ;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=( FragTrap const &rhs )
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}
	std::cout << "FragTrap " << this->_name << " assignment operator called" << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys( void )
{
	if (this->_hitPoint > 0)
		std::cout << "FragTrap " << this->_name << ": HIGH FIVES??" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " cannot give high fives, because he is dead." << std::endl;
}

std::ostream	&operator<<( std::ostream &obj, FragTrap const &insert )
{
	obj << "_name: " << insert.getName() << std::endl
		<< "_hitPoint: " << insert.getHitPoint() << std::endl
		<< "_energyPoint: " << insert.getEnergyPoint() << std::endl
		<< "_attackDamage: " << insert.getAttackDamage() << std::endl;
	return (obj);
}
