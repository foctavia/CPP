/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:37:12 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/16 10:23:43 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;
		
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const &src );

		virtual ~PresidentialPardonForm( void );
		
		PresidentialPardonForm	&operator=( PresidentialPardonForm const &rhs );

		const std::string		getTarget( void ) const;

		virtual void			execute( Bureaucrat const &executor ) const;
};

std::ostream	&operator<<( std::ostream &obj, PresidentialPardonForm *insert );

#endif
