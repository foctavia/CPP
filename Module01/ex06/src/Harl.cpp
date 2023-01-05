/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:43:50 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/05 11:47:39 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
	return ;
}

Harl::~Harl( void )
{
	return ;
}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
		<< "I really do!" << std::endl << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money." << std::endl
		<< "You didn't put enough bacon in my burger!" << std::endl
		<< "If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free." << std::endl
		<< "I've been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl
		<< "This is unacceptable!" << std::endl
		<< "I want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::switch_off( void )
{
	std::cout << "[ SWITCHOFF ]" << std::endl
		<< "Ahh, I'm tired..." << std::endl
		<< "I'll take a nap..." << std::endl << std::endl;
}

void	Harl::complain( std::string level )
{
	int			i = 0;
	enum		idx { DEBUG = 0, INFO, WARNING, ERROR, SWITCHOFF };
	void		(Harl::*func_ptr[5])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::switch_off };
	std::string	complain[5] = { "DEBUG", "INFO", "WARNING", "ERROR", "SWITCHOFF" };
	
	while (i < 5)
	{
		if (complain[i] == level)
			break ;
		i++;
	}
	switch(i)
	{
		case DEBUG:
			(this->*func_ptr[DEBUG])();
		case INFO:
			(this->*func_ptr[INFO])();
		case WARNING:
			(this->*func_ptr[WARNING])();
		case ERROR:
			(this->*func_ptr[ERROR])();
			break ;
		case SWITCHOFF:
			(this->*func_ptr[SWITCHOFF])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}
