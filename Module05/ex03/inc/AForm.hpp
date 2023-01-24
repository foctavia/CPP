/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:46:13 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/24 11:55:49 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;

	public:
		AForm( void );
		AForm( const std::string name );
		AForm( const unsigned int gradeToSign, const unsigned int gradeToExec );
		AForm( const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExec );
		AForm( AForm const &src );

		virtual ~AForm( void );

		AForm				&operator=( AForm const &rhs );
		
		const std::string	getName( void ) const;
		unsigned int		getGradeToSign( void ) const;
		unsigned int		getGradeToExecute( void ) const;
		bool				getSigned( void ) const;
		
		void				checkGrade( const unsigned int grade );
		void				beSigned( Bureaucrat &b );
		virtual void		execute( Bureaucrat const &executor ) const;
		
		class AFormException : public std::exception
		{
			public:
				virtual const char	*what( void ) const throw() = 0;
		};
		
		class GradeTooLowException : public AFormException
		{
			public:
				virtual const char	*what( void ) const throw();
		};
		
		class GradeTooHighException : public AFormException
		{
			public:
				virtual const char	*what( void ) const throw();
		};

		class FormIsSignedException : public AFormException
		{
			public:
				virtual const char	*what( void ) const throw();
		};

		class FormNotSignedException : public AFormException
		{
			public:
				virtual const char	*what( void ) const throw();
		};
};

std::ostream	&operator<<( std::ostream &obj, AForm *insert );

#endif
