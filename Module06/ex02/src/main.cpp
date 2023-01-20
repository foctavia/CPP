/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:23:37 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/20 10:20:53 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main( void )
{
	std::srand(time(NULL));
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << "\tTEST #" << i + 1 << std::endl;
		
		Base	*ptr = generate();
		Base	&ref = *ptr;

		identify(ptr);
		identify(ref);

		delete ptr;

		std::cout << std::endl;
	}
	
	return (0);
}
