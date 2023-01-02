/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:09:52 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/02 17:30:02 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	Contact::_fields_name[5] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

Contact::Contact()
{
	for (int i = first_name; i <= darkest_secret; i++)
		this->_info[i] = std::string();
	return ;
}

Contact::~Contact()
{
	return ;
}

bool	Contact::set_contact()
{
	for(int i = first_name; i <= darkest_secret; i++)
	{
		std::cout << Contact::_fields_name[i] << ":" << std::endl;
		while (!(std::getline(std::cin, this->_info[i])) || this->_info[i].length() == 0)
		{
			std::cout << "Please fill in information. " << Contact::_fields_name[i]
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
