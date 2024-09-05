/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:00:12 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 15:01:09 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(Cure const &src) : AMateria(src)
{
	*this = src;
}

Cure::~Cure(void)
{
}

Cure & Cure::operator=(Cure const &src)
{
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

Cure * Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}