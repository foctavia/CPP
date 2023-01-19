/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:36:36 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/19 12:14:28 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int	main( void )
{
	Data	ptr1;
	Data	ptr2;

	ptr1.str = "Bonjour";
	ptr1.i = 1;
	ptr1.len = ptr1.str.length();
	ptr1.prev = NULL;
	ptr1.next = &ptr2;

	ptr2.str = "Ca va?";
	ptr2.i = 2;
	ptr2.len = ptr2.str.length();
	ptr2.prev = &ptr1;
	ptr2.next = NULL;

	std::cout << GREEN("DATA STRUCT #1") << std::endl
		<< "current address:\t" << &ptr1 << std::endl
		<< "str:\t\t\t" << ptr1.str << std::endl
		<< "index:\t\t\t" << ptr1.i << std::endl
		<< "legth:\t\t\t" << ptr1.len << std::endl
		<< "address of next:\t" << ptr1.next << std::endl
		<< "address of prev:\t" << ptr1.prev << std::endl << std::endl;

	std::cout << GREEN("DATA STRUCT #2") << std::endl
		<< "current address:\t" << &ptr2 << std::endl
		<< "str:\t\t\t" << ptr2.str << std::endl
		<< "index:\t\t\t" << ptr2.i << std::endl
		<< "legth:\t\t\t" << ptr2.len << std::endl
		<< "address of next:\t" << ptr2.next << std::endl
		<< "address of prev:\t" << ptr2.prev << std::endl << std::endl;
	
	Serialization	srl;

	Data	*serialized = srl.deserialize(srl.serialize(&ptr1));

	std::cout << GREEN("SERIALIZED STRUCT") << std::endl
		<< "current address:\t" << serialized << std::endl
		<< "str:\t\t\t" << serialized->str << std::endl
		<< "index:t\t\t\t" << serialized->i << std::endl
		<< "legth:\t\t\t" << serialized->len << std::endl
		<< "address of next:\t" << serialized->next << std::endl
		<< "address of prev:\t" << serialized->prev << std::endl << std::endl;
		
	return (0);
}
