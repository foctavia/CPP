/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:46:13 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/12 02:36:52 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;

	public:
		Form( void );
		Form( const std::string name );
		Form( const unsigned int gradeToSign, const unsigned int gradeToExec );
		Form( const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExec );
		Form( Form const &src );

		~Form( void );

		Form				&operator=( Form const &rhs );
		
		const std::string	getName( void ) const;
		unsigned int	getGradeToSign( void ) const;
		unsigned int	getGradeToExecute( void ) const;
		bool				getSigned( void ) const;
		
		void				checkGrade( const unsigned int grade );
		void				beSigned( Bureaucrat &b );
		
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

std::ostream	&operator<<( std::ostream &obj, Form const &insert );

#endif
