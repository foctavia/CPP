/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 00:06:25 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/16 17:11:01 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ) : _name( "unknown" ), _signed( false ), _gradeToSign( 150 ), _gradeToExecute( 150 )
{
	std::cout << "Form default constructor called" << std::endl;
	return ;
}

AForm::AForm( const std::string name )
	: _name( name ), _signed( false ), _gradeToSign( 150 ), _gradeToExecute( 150 )
{
	std::cout << "Constructor for form " << this->_name << " called" << std::endl;
	return ;
}

AForm::AForm( const unsigned int gradeToSign, const unsigned int gradeToExec )
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

AForm::AForm( const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExec )
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

AForm::AForm( AForm const &src )
	: _name( "unknown" ), _gradeToSign( 150 ), _gradeToExecute( 150 )
{
	*this = src;
	std::cout << "Copy constructor for form " << this->_name << " called" << std::endl;
	return ;
}

AForm::~AForm( void )
{
	std::cout << "Destructor for form " << this->_name << " called" << std::endl;
	return ;
}

AForm	&AForm::operator=( AForm const &rhs )
{
	if (this != &rhs)
		this->_signed = rhs.getSigned();
	std::cout << "Form assignment operator called" << std::endl;
	return (*this);
}

const std::string	AForm::getName( void ) const
{
	return (this->_name);
}

unsigned int	AForm::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

unsigned int	AForm::getGradeToExecute( void ) const
{
	return (this->_gradeToExecute);
}

bool	AForm::getSigned( void ) const
{
	return (this->_signed);
}

void	AForm::checkGrade( const unsigned int grade )
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
}

void	AForm::beSigned( Bureaucrat &b )
{
	if (this->_signed == true)
		std::cerr << b.getName() << RED(" couldn't sign form ") << this->_name
			<< " because " << RED("it is already signed") << std::endl;
	else if (b.getGrade() <= this->getGradeToSign())
	{
		this->_signed = true;
		std::cout << b.getName() << GREEN(" signed form ") << this->_name << std::endl;
	}
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute( Bureaucrat const &executor ) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
}

const char	*AForm::GradeTooLowException::what( void ) const throw()
{
	return (RED("Grade too low"));
}

const char	*AForm::GradeTooHighException::what( void ) const throw()
{
	return (RED("Grade too high"));
}

const char	*AForm::FormNotSignedException::what( void ) const throw()
{
	return (RED("Form is not signed yet"));
}

std::ostream	&operator<<( std::ostream &obj, AForm *insert )
{
	obj << "Form " << insert->getName() << std::endl
		<< "Grade to be signed : " << insert->getGradeToSign() << std::endl
		<< "Grade to be executed : " << insert->getGradeToExecute() << std::endl
		<< "Status : ";
	if (insert->getSigned())
		obj << GREEN("Signed") << std::endl;
	else
		obj << RED("Not signed") << std::endl;
		
	return (obj);
}
