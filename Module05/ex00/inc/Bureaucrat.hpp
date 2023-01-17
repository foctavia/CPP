/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:50:10 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/17 13:43:04 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# define RED(s) "\033[1;31m" s "\033[m"
# define GREEN(s) "\033[1;32m" s "\033[m"
# define YELLOW(s) "\033[1;33m" s "\033[m"
# define BLUE(s) "\033[1;34m" s "\033[m"

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;

		void				setGrade( unsigned int grade );
	
	public:
		Bureaucrat( void );
		Bureaucrat( const std::string name );
		Bureaucrat( unsigned int grade );
		Bureaucrat( const std::string name , unsigned int grade );
		Bureaucrat( Bureaucrat const &src );

		~Bureaucrat( void );
		
		Bureaucrat			&operator=( Bureaucrat const &rhs );

		const std::string	getName( void ) const;
		unsigned int		getGrade( void ) const;
		
		void				incrementGrade( void );
		void				decrementGrade( void );
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};
};

std::ostream	&operator<<( std::ostream &obj, Bureaucrat *insert );

#endif
