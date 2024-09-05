/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 01:25:28 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 08:38:11 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy operateur called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "Brain assignation operator called" << std::endl;
	*this->ideas_ = *rhs.ideas_;
	return (*this);
}

const std::string	*Brain::getIdeas(void) const
{
	return (this->ideas_);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index > NB_IDEAS - 1)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	this->ideas_[index] = idea;
}

void Brain::setIdeas(const std::string *ideas)
{
	for (int i = 0; i < NB_IDEAS; i++)
		this->ideas_[i] = ideas[i];
}
