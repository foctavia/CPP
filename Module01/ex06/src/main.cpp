/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:43:47 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/05 10:52:11 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char	**argv)
{
	Harl	harl;
	
	if (argc <= 1)
		return (EXIT_SUCCESS);
	harl.complain(argv[1]);	
	return (EXIT_SUCCESS);
}
