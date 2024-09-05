/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:11:48 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 15:14:56 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < this->materiaSize_; i++)
		this->materia_[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < this->materiaSize_; i++)
	{
		if (this->materia_[i] != NULL)
			delete this->materia_[i];
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const &src)
{
	if (this != &src)
	{
		for (int i = 0; i < this->materiaSize_; i++)
		{
			if (this->materia_[i] != NULL)
				delete this->materia_[i];
			if (src.materia_[i] != NULL)
				this->materia_[i] = src.materia_[i]->clone();
			else
				this->materia_[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria * materia)
{
	for (int i = 0; i < this->materiaSize_; i++)
	{
		if (this->materia_[i] == NULL)
		{
			this->materia_[i] = materia;
			//std::cout << "The materia " << materia->getType() << " is copied." << std::endl;
			return ;
		}
	}
	std::cout << "No space available for copy" << std::endl;
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->materiaSize_; i++)
	{
		if (this->materia_[i] != NULL && this->materia_[i]->getType() == type)
		{
			//std::cout << "The materia " << type << " is created." << std::endl;
			return (this->materia_[i]->clone());
		}
	}
	std::cout << "No space available for creation" << std::endl;
	return (NULL);
}