/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:36:43 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/17 13:50:51 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;
	
		ShrubberyCreationForm( void );
		
	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const &src );

		virtual ~ShrubberyCreationForm( void );

		ShrubberyCreationForm	&operator=( ShrubberyCreationForm const &rhs );

		const std::string		getTarget( void ) const;

		virtual void			execute( Bureaucrat const &executor ) const;
		
};

std::ostream	&operator<<(std::ostream &obj, ShrubberyCreationForm *insert);

#endif
