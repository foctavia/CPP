/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:13:55 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/05 19:26:46 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	display_usage( void ) const
{
	std::cout << "Program needs 3 parameters to work, a valid filename and 2 strings." << std::endl
			<< "Usage : ./replace <filename> <str1> <str2>" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		display_usage();
		return -1;
	}
	
	const char	*filename = argv[1];
	std::string	str1(argv[2]);
	std::string	str2(argv[3]);
	ifstream	infile;
	ofstream	outfile;
	
	infile.open(filename, ios::in)
	if (!infile)
	{
		std::cout << "ERROR : filename is not valid" << std::endl;
		display_usage();
		return -1;
	}
	return 0;
}
