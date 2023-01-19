/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:22:57 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/19 10:55:46 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert( void )
	: _arg( "" )
	, _type( 0 )
	, _char( 0 )
	, _int( 0 )
	, _float( 0 )
	, _double( 0 )
{
	return ;
}

Convert::Convert( const std::string arg) 
	: _arg( arg )
	, _type( 0 )
	, _char( 0 )
	, _int( 0 )
	, _float( 0 )
{
	this->_double = atof(arg.c_str());
	this->convertArg();
	this->displayResult();
	return ;
}

Convert::Convert( Convert const &src ) : _arg(src.getArg())
{
	*this = src;
	this->displayResult();
}

Convert::~Convert( void )
{
	return ;
}

Convert	&Convert::operator=( Convert const &rhs )
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		this->_char = rhs.getChar();
		this->_int = rhs.getInt();
		this->_float = rhs.getFloat();
		this->_double = rhs.getDouble();
	}
	return *this;
}

int	Convert::checkType( void )
{
	if (this->_arg.compare("nan") == 0 || this->_arg.compare("nanf") == 0
		|| this->_arg.compare("+inf") == 0 || this->_arg.compare("-inf") == 0
		|| this->_arg.compare("+inff") == 0 || this->_arg.compare("-inff") == 0)
		return (NAN_INF);
	else if (this->_arg.length() == 1
		&& (this->_arg[0] == '+' || this->_arg[0] == '-' || this->_arg[0] == '.' || this->_arg[0] == 'f'))
		return (CHAR);
	else if (this->_arg.find_first_of("+-") != this->_arg.find_last_of("+-")) // ex. '-012+93'
		return (ERROR);
	else if (this->_arg.find_first_not_of("+-0123456789") == std::string::npos)
		return (INT);
	else if (this->_arg.find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (this->_arg.find_first_of(".") != this->_arg.find_last_of(".") // ex. '1..3'
			|| isdigit(this->_arg[this->_arg.find_first_of(".") + 1]) == false // ex. '12.'
			|| this->_arg[0] == '.') // ex. '.26'
			return (ERROR);
		else
			return (DOUBLE);
	}
	else if (this->_arg.find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (this->_arg.find_first_of("f") != this->_arg.find_last_of("f") // ex. '0.1ff'
			|| this->_arg.find_first_of(".") != this->_arg.find_last_of(".") // ex. '1..3f'
			|| this->_arg.find_first_of("f") - this->_arg.find_first_of(".") == 1 // ex. '0.f'
			|| this->_arg[this->_arg.find_first_of("f") + 1] != '\0' // ex. '0.0f2'
			|| this->_arg[0] == '.') // ex. '.26'
			return (ERROR);
		else
			return (FLOAT);
	}
	else if (this->_arg.length() == 1
		&& (std::isprint(this->_arg[0]) || std::isalpha(this->_arg[0])))
		return (CHAR);
	else
		return (ERROR);
}

void	Convert::checkChar( void ) const
{
	if (this->_double > UCHAR_MAX || this->_double < 0 
		|| std::isfinite(this->_double) == false
		|| this->_type == NAN_INF)
		throw Convert::ImpossibleException();
	if (isprint(this->_char) == false)
		throw Convert::NonDisplayableException();
}

void	Convert::checkInt( void ) const
{
	if (this->_double > std::numeric_limits<int>::max()
		|| this->_double < std::numeric_limits<int>::min() 
		|| std::isfinite(this->_double) == false
		|| this->_type == NAN_INF)
		throw Convert::ImpossibleException();
}

void	Convert::fromChar( void )
{
	this->_char = static_cast<unsigned char>(this->_arg[0]);
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<double>(this->_char);
}

void	Convert::fromInt( void )
{
	this->_int = static_cast<int>(this->_double);
	this->_float = static_cast<float>(this->_double);
	this->_char = static_cast<unsigned char>(this->_int);
}

void	Convert::fromFloat( void )
{
	this->_float = static_cast<float>(this->_double);
	this->_char = static_cast<char>(this->_float);
	this->_int = static_cast<int>(this->_float);
}

void	Convert::fromDouble( void )
{
	this->_char = static_cast<char>(this->_double);
	this->_int = static_cast<int>(this->_double);
	this->_float = static_cast<float>(this->_double);
}

void	Convert::convertArg( void )
{
	void	(Convert::*funcConverts[])( void ) 
		= { &Convert::fromChar, &Convert::fromInt, &Convert::fromFloat, &Convert::fromDouble };
	int		types[] = { CHAR, INT, FLOAT, DOUBLE };
	
	this->_type = this->checkType();

	if (this->_type == NAN_INF)
		return ;
	int i;
	for (i = 0; i < 4; i++)
	{
		if (this->_type == types[i])
		{
			(this->*funcConverts[i])();
			break ;
		}
	}
	if (i == 4)
		throw Convert::ErrorException();
}

void	Convert::displayChar( void ) const
{
	std::cout << "char: ";
	try
	{
		this->checkChar();
		std::cout << "'" << this->_char << "'" << std::endl;
	}
	catch (Convert::ConvertException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Convert::displayInt( void ) const
{
	std::cout << "int: ";
	try
	{
		this->checkInt();
		std::cout << this->_int << std::endl;
	}
	catch (Convert::ConvertException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Convert::displayFloat( void ) const
{
	std::cout << "float: ";
	if (this->_type == NAN_INF)
	{
		std::cout << this->_arg;
		if (this->_arg.compare("nan") == 0
			|| this->_arg.compare("+inf") == 0
			|| this->_arg.compare("-inf") == 0)
			std::cout << "f";
		std::cout << std::endl;
	}
	else
	{
		std::cout << this->_float;
		if (this->_float - this->_int == 0)
			std::cout << ".0f";
		else
			std::cout << "f";
		std::cout << std::endl;
	}
	
}

void	Convert::displayDouble( void ) const
{
	std::cout << "double: ";
	if (this->_type == NAN_INF)
	{
		if (this->_arg[0] == '+')
			std::cout << "+inf";
		else if (this->_arg[0] == '-')
			std::cout << "-inf";
		else
			std::cout << "nan";
		std::cout << std::endl;
	}
	else
	{
		std::cout << this->_double;
		if (this->_double > std::numeric_limits<int>::max()
			|| this->_double < std::numeric_limits<int>::min()
			|| this->_double - this->_int == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void	Convert::displayResult( void ) const
{
	this->displayChar();
	this->displayInt();
	this->displayFloat();
	this->displayDouble();
}

const std::string	Convert::getArg( void ) const
{
	return (this->_arg);
}

int	Convert::getType( void ) const
{
	return (this->_type);
}

char	Convert::getChar( void ) const
{
	return (this->_char);
}

int	Convert::getInt( void ) const
{
	return (this->_int);
}

float	Convert::getFloat( void ) const
{
	return (this->_float);
}

double	Convert::getDouble( void ) const
{
	return (this->_double);
}

const char	*Convert::NonDisplayableException::what( void ) const throw ()
{
	return (RED("Non displayable"));
}

const char	*Convert::ImpossibleException::what( void ) const throw ()
{
	return (RED("impossible"));
}

const char	*Convert::ErrorException::what( void )const throw ()
{
	return (RED("ERROR : Input is impossible to convert or is not part of any type of the literal permitted"));
}
