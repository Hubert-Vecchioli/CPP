/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:56:45 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 12:09:48 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), target_("Unkown")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("PresidentialPardonForm", 25, 5), target_(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) : AForm(copy), target_(copy.target_)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	(void)rhs;
	return (*this);
}

void	PresidentialPardonForm::beExecuted(void) const
{
	std::cout << this->target_ << " is now pardoned by Zafod Beeblebrox." << std::endl;
}