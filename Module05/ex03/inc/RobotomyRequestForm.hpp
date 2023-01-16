/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:37:08 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/18 10:01:05 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;
		
		RobotomyRequestForm( void );
		
	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const &src );

		virtual ~RobotomyRequestForm( void );
		
		RobotomyRequestForm	&operator=( RobotomyRequestForm const &rhs );

		const std::string	getTarget( void ) const;

		virtual void		execute( Bureaucrat const &executor ) const;

};

std::ostream	&operator<<( std::ostream &obj, RobotomyRequestForm *insert );

#endif
