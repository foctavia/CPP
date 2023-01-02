/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:08:33 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/02 20:29:21 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

Account::_nbAccounts = 0;
Account::_totalAmount = 0;
Account::_totalNbDeposits = 0;
Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
	return ;
}

Account::Account( int initial_deposit )
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	return ;
}

Account::~Account( void )
{
	return ;
}

static int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

static int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

static int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);	
}

static int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

static int	Account::displayAccountsInfos( void )
{
	
}

void	Account::makeDeposit( int deposit )
{
	
}

bool	Account::makeWithdrawal( int withdrawal )
{
	
}

int	Account::checkAmount( void ) const
{
	
}

void	displayStatus( void ) const
{
	
}

static void	Account::_displayTimestamp( void )
{
	
}
