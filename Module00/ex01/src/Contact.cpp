/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:09:52 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/05 11:55:54 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	Contact::_fields[5] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

Contact::Contact( void )
{
	for (int i = first_name; i <= darkest_secret; i++)
		this->_info[i] = std::string();
	return ;
}

Contact::~Contact( void )
{
	return ;
}

bool	Contact::set_contact( void )
{
	for(int i = first_name; i <= darkest_secret; i++)
	{
		std::cout << Contact::_fields[i] << ":" << std::endl;
		while (!(std::getline(std::cin, this->_info[i])) || this->_info[i].length() == 0)
		{
			std::cout << "Please fill in information. " << Contact::_fields[i]
				<< " is mandatory." << std::endl;
		}
	}
	std::cout << "Contact saved." << std::endl;
	return (true);
}

void	Contact::get_contact(int idx) const
{
	std::cout << "|" << std::setw(10) << idx;
	for (int i = first_name; i <= nickname; i++)
	{
		std::cout << "|";
		if (this->_info[i].length() > 10)
			std::cout << this->_info[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_info[i];
	}
	std::cout << "|" << std::endl;
}
