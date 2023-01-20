/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:38:35 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/20 16:08:37 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	ft_tolower( char &c )
{
	c = std::tolower(c);
}

void	ft_toupper( char &c )
{
	c = std::toupper(c);
}

int	main( void )
{
	char	arr1[] = "BONJOUR";

	std::cout << "ARRAY #1 (before)" << std::endl;
	::iter(arr1, sizeof(arr1) / sizeof(char), print);
	std::cout << std::endl << std::endl;
	
	::iter(arr1, sizeof(arr1) / sizeof(char), ft_tolower);
	
	std::cout << "ARRAY #1 (after)" << std::endl;
	::iter(arr1, sizeof(arr1) / sizeof(char), print);
	std::cout << std::endl << std::endl;

	std::cout << "--------------------------------------------------" 
		<< std::endl << std::endl;
	
	char	arr2[] = "coucou";

	std::cout << "ARRAY #2 (before)" << std::endl;
	::iter(arr2, sizeof(arr2) / sizeof(char), print);
	std::cout << std::endl << std::endl;
	
	::iter(arr2, sizeof(arr2) / sizeof(char), ft_toupper);
	
	std::cout << "ARRAY #2 (after)" << std::endl;
	::iter(arr2, sizeof(arr2) / sizeof(char), print);
	std::cout << std::endl << std::endl;

	std::cout << "--------------------------------------------------" 
		<< std::endl << std::endl;
	
	int		tab[] = {0,1,2,3,4};
	Awesome	tab2[5];

	std::cout << "ARRAY OF INT" << std::endl;
	::iter(tab, 5, print);
	std::cout << std::endl << std::endl
		<< "ARRAY OF CLASS" << std::endl;
	::iter(tab2, 5, print);
	std::cout << std::endl << std::endl;

	return 0;
}