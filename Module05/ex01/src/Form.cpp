/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 00:06:25 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/15 19:08:59 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name( "unknown" ), _signed( false ), _gradeToSign( 150 ), _gradeToExecute( 150 )
{
	std::cout << "Form default constructor called" << std::endl;
	return ;
}

Form::Form( const std::string name )
	: _name( name ), _signed( false ), _gradeToSign( 150 ), _gradeToExecute( 150 )
{
	std::cout << "Constructor for form " << this->_name << " called" << std::endl;
	return ;
}

Form::Form( const unsigned int gradeToSign, const unsigned int gradeToExec )
	: _name( "unknown" ), _signed( false ), _gradeToSign( gradeToSign ), _gradeToExecute( gradeToExec )
{
	std::cout << "Constructor for form " << this->_name 
		<< " with grade " << this->_gradeToSign 
		<< " required to sign it, and grade " << this->_gradeToExecute
		<< " required to execute it, called" << std::endl;
	this->checkGrade(gradeToSign);
	this->checkGrade(gradeToExec);
	return ;
}

Form::Form( const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExec )
	: _name( name ), _signed( false ), _gradeToSign( gradeToSign ), _gradeToExecute( gradeToExec )
{
	std::cout << "Constructor for form " << this->_name 
		<< " with grade " << this->_gradeToSign 
		<< " required to sign it, and grade " << this->_gradeToExecute
		<< " required to execute it, called" << std::endl;
	this->checkGrade(gradeToSign);
	this->checkGrade(gradeToExec);
	return ;
}

Form::Form( Form const &src )
	: _name( "unknown" ), _gradeToSign( 150 ), _gradeToExecute( 150 )
{
	*this = src;
	std::cout << "Copy constructor for form " << this->_name << " called" << std::endl;
	return ;
}

Form::~Form( void )
{
	std::cout << "Destructor for form " << this->_name << " called" << std::endl;
	return ;
}

Form	&Form::operator=( Form const &rhs )
{
	if (this != &rhs)
		this->_signed = rhs.getSigned();
	std::cout << "Form assignment operator called" << std::endl;
	return (*this);
}

const std::string	Form::getName( void ) const
{
	return (this->_name);
}

unsigned int	Form::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

unsigned int	Form::getGradeToExecute( void ) const
{
	return (this->_gradeToExecute);
}

bool	Form::getSigned( void ) const
{
	return (this->_signed);
}

void	Form::checkGrade( const unsigned int grade )
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

void	Form::beSigned( Bureaucrat &b )
{
	if (this->_signed == true)
		std::cerr << b.getName() << " couldn't sign form " << this->_name
			<< " because it is already signed" << std::endl;
	else if (b.getGrade() <= this->getGradeToSign())
	{
		this->_signed = true;
		std::cout << b.getName() << " signed form " << this->_name << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}

const char	*Form::GradeTooLowException::what( void ) const throw()
{
	return ("Grade too low");
}

const char	*Form::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high");
}

std::ostream	&operator<<( std::ostream &obj, Form *insert )
{
	obj << "Form " << insert->getName() << std::endl
		<< "Grade to be signed : " << insert->getGradeToSign() << std::endl
		<< "Grade to be executed : " << insert->getGradeToSign() << std::endl
		<< "Status : ";
	if (insert->getSigned())
		obj << "Signed" << std::endl;
	else
		obj << "Not signed" << std::endl;
		
	return (obj);
}
