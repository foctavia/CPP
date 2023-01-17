/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foctavia <foctavia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:54:03 by foctavia          #+#    #+#             */
/*   Updated: 2023/01/17 10:40:56 by foctavia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 2; i++)
		this->_materias[i] = NULL;
	return ;
}

MateriaSource::MateriaSource( MateriaSource const &src )
{
	*this = src;
	return ;
}

MateriaSource::~MateriaSource( void )
{
	for(int i = 0; i < 2; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
	return ;
}

MateriaSource	&MateriaSource::operator=( MateriaSource const &rhs )
{
	if (this == &rhs)
	{
		for(int i = 0; i < 2; i++)
			this->_materias[i] = rhs._materias[i];
	}
	return (*this);
}

void 		MateriaSource::learnMateria( AMateria* m)
{
	int	i = 0;
	while (this->_materias[i])
		i++;
	if (i >= 2)
	{
		std::cout << "Reached maximum capacity of 4 materia per materiaSource" << std::endl;
		return ;
	}
	this->_materias[i] = m;
}

AMateria	*MateriaSource::createMateria( std::string const &type )
{
	for (int i = 0; this->_materias[i]; i++)
	{
		if (this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	std::cout << "Type " << type << " does not matched any materias" << std::endl;
	return (NULL);
}
