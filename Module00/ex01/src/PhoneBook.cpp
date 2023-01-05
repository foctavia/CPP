/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:45:38 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/05 17:32:09 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook( void )
{
	this->_idx = 0;
	this->_full = false;
	return ;
}

PhoneBook::~PhoneBook( void )
{
	return ;
}

void	PhoneBook::set_info( void )
{
	std::string	input;
	if (this->_full == false)
	{
		std::cout << std::endl << "Contact No." << this->_idx + 1 << std::endl;
		if (this->_contacts[this->_idx].set_contact() == true)
		{
			if (this->_idx == 7)
				this->_full = true;
			else
				this->_idx++;
		}
	}
	else
	{
		std::cout << "Your phonebook is full. If you want to add a new contact, your oldest contact stored will be discarded." << std::endl;
		std::cout << "Please press '1' to proceed." << std::endl;
		getline(std::cin, input);
		if (!std::cin)
		{
			std::cout << std::endl << "Exiting phonebook now." << std::endl;
			exit(0);
		}
		if (input.compare("1") == 0)
		{
			for (int i = 1; i < 8; i++)
				this->_contacts[i - 1] = this->_contacts[i];
			std::cout << "Contact No.8" << std::endl;
			this->_contacts[this->_idx].set_contact();
		}
		else
			std::cout << "Back to main menu." << std::endl;
	}
}

void	PhoneBook::get_info( void ) const
{	
	std::string	input;
	
	std::cout << std::endl << "Please enter the contact index available." << std::endl;
	while (!(std::getline(std::cin, input)) || input.length() > 1 ||
		input.compare("1") < 0 || input.compare("8") > 0 ||
		(std::atoi(input.c_str()) - 1 >= this->_idx && this->_full == false))
	{
		if (!std::cin)
		{
			std::cout << std::endl << "Exiting phonebook now." << std::endl;
			exit(0);
		}
		if (this->_idx == 1)
		{
			std::cin.clear();
			std::cout << "You only have 1 contact saved, please enter number 1."
				<< std::endl;
		}
		else if (this->_idx == 7 && this->_full == true)
		{
			std::cin.clear();
			std::cout << "Please enter number between 1 and 8." << std::endl;
		}
		else
		{
			std::cin.clear();
			std::cout << "Please enter number between 1 and " << this->_idx << "."
				<< std::endl;
		}
	}
	int i = std::atoi(input.c_str());
	if (i > 0)
	{
		std::cout << "First Name\t: " << this->_contacts[i - 1].get_contact(0) << std::endl
			<< "Last Name\t: " << this->_contacts[i - 1].get_contact(1) << std::endl
			<< "Nickname\t: " << this->_contacts[i  -1].get_contact(2) << std::endl
			<< "Phone Number\t: " << this->_contacts[i - 1].get_contact(3) << std::endl
			<< "Darkest Secret\t: " << this->_contacts[i - 1].get_contact(4) << std::endl;
	}
	else
		std::cout << "Back to main menu." << std::endl;
}

void	PhoneBook::display_phonebook( void ) const
{
	std::cout << std::endl << "|-----------------PHONEBOOK-----------------|" << std::endl;
	if (this->_idx == 0)
		std::cout << "Your phonebook is empty." << std::endl;
	else
	{
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		for (int i = 0; i < this->_idx || (i == 7 && this->_full == true); i++)
		{
			this->_contacts[i].display_contact(i + 1);
			std::cout << "|----------|----------|----------|----------|" << std::endl;
		}
		std::cout << "|-------------------------------------------|" << std::endl;
		
		this->get_info();
	}
}

void	PhoneBook::display_option( void )
{
	std::cout << std::endl << "Please enter your command (ADD / SEARCH / EXIT) :" << std::endl;
}
