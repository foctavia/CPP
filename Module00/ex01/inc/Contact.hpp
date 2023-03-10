/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:22:24 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/05 17:47:16 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
	private:
		static std::string	_fields[5];
		std::string			_info[5];

		enum _idx
		{
			first_name = 0,
			last_name,
			nickname,
			phone_number,
			darkest_secret
		};
		
	public:
		Contact( void );
		~Contact( void );

		bool		set_contact();
		std::string	get_contact(int field_idx) const;
		void		display_contact(int idx) const;
};

#endif
