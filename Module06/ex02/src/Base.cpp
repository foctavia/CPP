/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:23:29 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/19 15:23:57 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::~Base( void )
{
	return ;
}

Base	*generate( void )
{
	switch(std::rand() % 3)
	{
		case 0:
			return (new A());
			break ;
		case 1:
			return (new B());
			break ;
		case 2:
			return (new C());
			break ;
		default:
			std::cerr << RED("ERROR : Failed generate a new Base : ") << std::strerror(errno) << std::endl;
			exit(1);
	}
}

void	identify( Base *p )
{
	std::cout << "Type from pointer\t: ";
	
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

void	identify( Base &p )
{
	std::cout << "Type from referance\t: ";
	
	std::string	types[] = { "A", "B", "C", "unknown" };
	int 		i = 0;
	
	while (i < 4)
	{
		try
		{
			if (i == 0)
			{
				A	&a = dynamic_cast<A &>(p);
				(void)a;
			}
			else if (i == 1)
			{
				B	&b = dynamic_cast<B &>(p);
				(void)b;
			}
			else if (i == 2)
			{
				C	&c = dynamic_cast<C &>(p);
				(void)c;
			}
			std::cout << types[i] << std::endl;
			break ;
		}
		catch (const std::bad_cast &bc)
		{
			i++;
		}
	}
}
