/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:43:52 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 15:35:49 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"

Character::Character(void) : name_("No Name")
{
	for (int i = 0; i < this->inventorySize_; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string const &name) : name_(name)
{
	for (int i = 0; i < this->inventorySize_; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const &src)
{
	*this = src;
}

Character::~Character(void)
{
	for (int i = 0; i < this->inventorySize_; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
}

Character & Character::operator=(Character const &src)
{
	if (this != &src)
	{
		this->name_ = src.name_;
		for (int i = 0; i < this->inventorySize_; i++)
		{
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
			if (src.inventory[i] != NULL)
				this->inventory[i] = src.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->name_);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < this->inventorySize_; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			//std::cout << "Equiped " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->inventorySize_)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	if (this->inventory[idx] == NULL)
	{
		std::cout << "Nothing to unequip" << std::endl;
		return ;
	}
	std::cout << "Unequiped " << this->inventory[idx]->getType() << std::endl;
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->inventorySize_)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (this->inventory[idx] == NULL)
	{
		std::cout << "Nothing to use" << std::endl;
		return;
	}
	this->inventory[idx]->use(target);
}
