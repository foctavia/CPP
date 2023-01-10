/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:13:55 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/10 18:04:51 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include <cstring>
#include <cstdlib>

void	display_usage( void )
{
	std::cerr << "Program needs 3 parameters to work, "
			<< "a valid file name, a string to search in the file, and another string to replace the search string." << std::endl
			<< "Usage : ./replace <filename> <search> <replace>" << std::endl;
	exit(1);
}

void	check_string( std::string search )
{
	if (search.empty())
	{
		std::cerr << "ERROR : <search> can not be an empty string" << std::endl;
		display_usage();
	}	
}

void	open_files( std::string &filename, std::ifstream &infile, std::ofstream &outfile)
{
	infile.open(filename.c_str(), std::ios::in);
	if (!infile)
	{
		std::cerr << "ERROR : " << filename << " : " << std::strerror(errno) << std::endl;
		display_usage();
	}
	filename.append(".replace");
	outfile.open(filename.c_str(), std::ios::out);
	if (!outfile)
	{
		std::cerr << "ERROR : " << filename << ": " << std::strerror(errno) << std::endl;
		display_usage();
	}
}

void	ft_replace( std::string &buffer, const std::string search, const std::string replace )
{
	size_t	search_len = search.length();
	size_t	replace_len = replace.length();
	size_t	find_post = buffer.find(search);

	while (find_post != std::string::npos)
	{
		buffer.erase(find_post, search_len);
		buffer.insert(find_post, replace);
		find_post = buffer.find(search, find_post + replace_len);
	}
}

void	get_file( std::string &search, std::string &replace, std::ifstream &infile, std::ofstream &outfile)
{
	std::string		buffer;
	
	while(std::getline(infile, buffer))
	{
		ft_replace(buffer, search, replace);
		outfile << buffer;
		if (infile.peek() != EOF)
			outfile << std::endl;
	}
}

void	close_files( std::ifstream &infile, std::ofstream &outfile)
{
	outfile.close();
	infile.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		display_usage();
	
	std::string		filename(argv[1]);
	std::string		search(argv[2]);
	std::string		replace(argv[3]);
	std::ifstream	infile;
	std::ofstream	outfile;
	
	check_string(search);
	open_files(filename, infile, outfile);
	get_file(search, replace, infile, outfile);
	close_files(infile, outfile);
	return 0;
}
