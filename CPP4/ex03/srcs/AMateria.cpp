/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:37:38 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 13:48:53 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"

AMateria::AMateria(void) : type_("No name")
{
}

AMateria::AMateria(std::string const & type) : type_(type)
{
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
}

AMateria::~AMateria(void)
{
}

AMateria & AMateria::operator=(AMateria const &src)
{
	if (this != &src)
		this->type_ = src.type_;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type_);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "Please don't use me, I am an abstraction" << std::endl;
	return;
}