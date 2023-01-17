/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:37:16 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/16 17:11:25 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
	: AForm( "PresidentialPardon", 25, 5 ), _target( "unknown target" )
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: AForm( "PresidentialPardon", 25, 5 ), _target( target )
{
	std::cout << "PresidentialPardonForm for " << this->_target << " constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &src )
{
	*this = src;
	std::cout << "PresidentialPardonForm for " << this->_target << " constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs )
{
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &rhs)
		this->AForm::operator=(rhs);
	return (*this);
}

const std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute( Bureaucrat const &executor ) const
{
	this->AForm::execute(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream	&operator<<( std::ostream &obj, PresidentialPardonForm *insert )
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
