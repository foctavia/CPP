/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:50:01 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/17 13:46:51 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name( "unknown" ), _grade( 150 )
{
	std::cout << this->getName() << ", bureaucrat grade " << this->getGrade()
		<< " default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( const std::string name ) : _name( name ), _grade( 150 )
{
	std::cout << this->getName() << ", bureaucrat grade " << this->getGrade()
		<< " constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( unsigned int grade ) : _name( "unknown" )
{
	std::cout << this->getName() << ", bureaucrat grade " << grade
		<< " constructor called" << std::endl;
	this->setGrade(grade);
	return ;
}

Bureaucrat::Bureaucrat( const std::string name, unsigned int grade ) : _name( name )
{
	std::cout << this->getName() << ", bureaucrat grade " << grade
		<< " constructor called" << std::endl;
	this->setGrade(grade);
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const &src )
{
	*this = src;
	std::cout << this->getName() << ", bureaucrat grade " << this->getGrade()
		<< " copy constructor called" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << this->getName() << ", bureaucrat grade " << this->getGrade()
		<< " destructor called" << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &rhs )
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	std::cout << this->getName() << ", bureaucrat grade " << this->getGrade()
		<< " assignment operator called" << std::endl;
	return (*this);
}

void	Bureaucrat::setGrade( unsigned int grade )
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

const std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade( void )
{
	std::cout << this->getName() << ", bureaucrat grade " << this->getGrade()
		<< " try increment their grade" << std::endl;
	this->setGrade(this->_grade - 1);
}
void	Bureaucrat::decrementGrade( void )
{
	std::cout << this->getName() << ", bureaucrat grade " << this->getGrade()
		<< " try decrement their grade" << std::endl;
	this->setGrade(this->_grade + 1);
}

void	Bureaucrat::signForm( Form &f )
{
	try
	{
		f.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cerr << this->_name << RED(" couldn't sign form ") << f.getName()
			<< " because " << e.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return (RED("Grade too low"));
}

const char	*Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return (RED("Grade too high"));
}

std::ostream	&operator<<( std::ostream &obj, Bureaucrat *insert )
{
	obj << insert->getName() << ", bureaucrat grade " << insert->getGrade() << std::endl;
	return (obj);
}
