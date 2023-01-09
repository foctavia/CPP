/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:02:04 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 15:25:30 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie	*zombie_horde;
	int		N = 3;

	zombie_horde = zombieHorde(N, "Zombie Horde member");
	if (!zombie_horde)
		return 1;
	for (int i = 0; i < N ; i++)
		zombie_horde[i].announce();
	delete [] zombie_horde;
	return 0;
}
