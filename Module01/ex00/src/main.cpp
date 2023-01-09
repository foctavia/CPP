/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:13:18 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 15:18:58 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie	*new_zombie = newZombie("New Zombie");

	new_zombie->Zombie::announce();
	randomChump("Random Chump");
	delete new_zombie;
	return 0;	
}
