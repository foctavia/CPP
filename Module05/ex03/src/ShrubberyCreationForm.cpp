/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:37:24 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/16 17:11:09 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: AForm( "ShrubberyCreation", 145, 137 ), _target( "unknown target" )
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: AForm( "ShrubberyCreation", 145, 137 ), _target( target )
{
	std::cout << "ShrubberyCreationForm for " << this->_target << " constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src )
{
	*this = src;
	std::cout << "ShrubberyCreationForm for " << this->_target << " copy constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs )
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &rhs)
		AForm::operator=(rhs);
	return (*this);
}

const std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute( Bureaucrat const &executor ) const
{
	this->AForm::execute(executor);
	
	std::ofstream	outfile ((this->getTarget() + "_shrubbery").c_str());
	if (!outfile)
	{
		std::cerr << RED("ERROR : ") << (this->getTarget() + "_shrubbery").c_str() 
			<< ": " << std::strerror(errno) << std::endl;
		return ;
	}
	outfile << "                                                     ." << std::endl
		<< "                                          .         ;" << std::endl
		<< "             .              .              ;%     ;;" << std::endl
		<< "               ,           ,                :;%  %;" << std::endl
		<< "                :         ;                   :;%;'     .," << std::endl
		<< "       ,.        %;     %;            ;        %;'    ,;" << std::endl
		<< "         ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl
		<< "          %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl
		<< "           ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl
		<< "            `%;.     ;%;     %;'         `;%%;.%;'" << std::endl
		<< "             `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl
		<< "                `:%;.  :;bd%;          %;@%;'" << std::endl
		<< "                  `@%:.  :;%.         ;@@%;'" << std::endl
		<< "                    `@%.  `;@%.      ;@@%;" << std::endl
		<< "                      `@%%. `@%%    ;@@%;" << std::endl
		<< "                        ;@%. :@%%  %@@%;" << std::endl
		<< "                          %@bd%%%bd%%:;" << std::endl
		<< "                            #@%%%%%:;;" << std::endl
		<< "                            %@@%%%::;" << std::endl
		<< "                            %@@@%(o);  . '" << std::endl
		<< "                            %@@@o%;:(.,'" << std::endl
		<< "                        `.. %@@@o%::;" << std::endl
		<< "                           `)@@@o%::;" << std::endl
		<< "                            %@@(o)::;" << std::endl
		<< "                           .%@@@@%::;" << std::endl
		<< "                           ;%@@@@%::;." << std::endl
		<< "                          ;%@@@@%%:;;;." << std::endl
		<< "                      ...;%@@@@@%%:;;;;,..    Gilo97" << std::endl << std::endl;
	outfile.close();
}

std::ostream	&operator<<( std::ostream &obj, ShrubberyCreationForm *insert )
{
	obj << insert->getName() << " Form for " << insert->getTarget() << std::endl
		<< "Grade to be signed : " << insert->getGradeToSign() << std::endl
		<< "Grade to be executed : " << insert->getGradeToExecute() << std::endl
		<< "Status : ";
	if (insert->getSigned())
		obj << GREEN("Signed") << std::endl;
	else
		obj << RED("Not signed") << std::endl;
		
	return (obj);
}

