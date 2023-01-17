/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:37:20 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/16 17:11:15 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
	: AForm( "RobotomyRequest", 72, 45 ), _target( "unknown target" )
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: AForm( "RobotomyRequest", 72, 45 ), _target( target )
{
	std::cout << "RobotomyRequestForm for " << this->_target << " constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &src )
{
	*this = src;
	std::cout << "RobotomyRequestForm for " << this->_target << " copy constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs )
{
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &rhs)
		this->AForm::operator=(rhs);
	return (*this);
}

const std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute( Bureaucrat const &executor ) const
{
	static int	robotomy_procedure = 0;
	
	this->AForm::execute(executor);
	std::cout << "<background noise> : Brrzzttt Brrzzztttt" << std::endl;
	if (robotomy_procedure++ % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy for " << this->_target << " has failed" << std::endl;
}

std::ostream	&operator<<( std::ostream &obj, RobotomyRequestForm *insert )
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
