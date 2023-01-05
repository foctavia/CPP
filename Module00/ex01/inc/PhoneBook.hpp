/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:06:12 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/05 17:23:54 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>

class PhoneBook
{
	private:
			Contact	_contacts[8];
			int		_idx;
			bool	_full;
	public:
			PhoneBook( void );
			~PhoneBook( void );

			void	set_info( void );
			void	get_info( void ) const;
			void	display_phonebook( void ) const;
			void	display_option( void );
};

#endif
