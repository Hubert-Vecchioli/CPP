/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:07:13 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 14:09:47 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(Ice const &src) : AMateria(src)
{
	*this = src;
}

Ice::~Ice(void)
{
}

Ice & Ice::operator=(Ice const &src)
{
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

Ice * Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
