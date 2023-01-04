/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:08:44 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/04 17:47:04 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main( void )
{
	PhoneBook	PhoneBook;
	bool		run = true;
	std::string	command;

	PhoneBook.display_option();
	while(run && std::getline(std::cin, command))
	{
		if (command.compare("ADD") == 0)
			PhoneBook.set_info();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.get_info();
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "Exiting phonebook now." << std::endl;
			run = false;
			exit (0);
		}
		command.clear();
		PhoneBook.display_option();
	}
	return (EXIT_SUCCESS);
}
