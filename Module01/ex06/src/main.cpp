/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:43:47 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/09 15:55:42 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char	**argv)
{
	Harl	harl;
	
	if (argc <= 1)
	{
		std::cerr << "Program accepted 1 parameter as Harl's mood." << std::endl
			<< "Option of the mood : DEBUG/INFO/WARNING/ERROR/SWITCHOFF" << std::endl;
		return 1;
	}
	harl.complain(argv[1]);	
	return 0;
}
