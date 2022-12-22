/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:09:12 by foctavia          #+#    #+#             */
/*   Updated: 2022/12/22 18:53:22 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	string	letter;
	int		i;
	
	i = 0;
	if (argc == 1)
		return 0;
	while (i < argc)
	{
		letter = argv[i];
		toupper(letter);
		std::cout << letter;
		i++;
	}
	return 0;
}
