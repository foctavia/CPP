/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:09:44 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/05 10:37:52 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void )
{
	Harl		harl;
	std::string	input = "\0";

	std::cout << "[ DEBUG ]" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "[ INFO ]" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl << "[ WARNING ]" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "[ ERROR ]" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	
	while (input != "DEBUG" && input != "INFO" && input != "WARNING" && input != "ERROR")
	{
		std::cout << "Please input Harl's mood ( DEBUG/INFO/WARNING/ERROR ): ";
		getline(std::cin, input);
		std::cout << std::endl;
		harl.complain(input);
	}
	return (EXIT_SUCCESS);
}
