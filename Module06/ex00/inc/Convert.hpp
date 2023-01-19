/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:22:51 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/19 10:51:48 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <climits>
# include <cstdlib>
# include <cstring>
# include <cctype>
# include <cmath>

# define RED(s) "\033[1;31m" s "\033[m"

# define ERROR -1
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define NAN_INF 5

class Convert
{
	private:
		const std::string	_arg;
		int					_type;
		char				_char;
		int					_int;
		float				_float;
		double				_double;
		
		Convert( void );
		
		int					checkType( void );
		void				checkChar( void ) const;
		void				checkInt( void ) const;

		void				fromChar( void );
		void				fromInt( void );
		void				fromFloat( void );
		void				fromDouble( void );

		void				convertArg( void );

		void				displayChar( void ) const;
		void				displayInt( void ) const;
		void				displayFloat( void ) const;
		void				displayDouble( void ) const;
		void				displayResult( void ) const;
		
	public:
		Convert( const std::string arg );
		Convert( Convert const &src );

		~Convert( void );

		Convert				&operator=( Convert const &rhs );

		const std::string	getArg( void ) const;
		int					getType( void ) const;
		char				getChar( void ) const;
		int					getInt( void ) const;
		float				getFloat( void ) const;
		double				getDouble( void ) const;
		
		class ConvertException : public std::exception
		{
			public:
				virtual const char	*what( void ) const throw() = 0;
		};
		
		class NonDisplayableException : public ConvertException
		{
			public:
				virtual const char	*what( void ) const throw();
		};

		class ImpossibleException : public ConvertException
		{
			public:
				virtual const char	*what( void ) const throw();
		};

		class ErrorException : public ConvertException
		{
			public:
				virtual const char	*what( void ) const throw();
		};
};

#endif
