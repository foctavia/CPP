/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:36:36 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/19 11:10:20 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int	main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cerr << RED("ERROR : Program needs 1 parameter to convert") << std::endl
			<< "Please enter one of the following literal : char / int / float / double"
			<< std::endl;
		return (1);
	}
	try
	{
		Convert	convert(argv[1]);
	}
	catch (Convert::ConvertException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
