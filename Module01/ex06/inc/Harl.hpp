/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:43:44 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/05 11:16:16 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		void	switch_off( void );

	public:
		Harl( void );
		~Harl( void );

		void	complain( std::string level );
};

#endif
