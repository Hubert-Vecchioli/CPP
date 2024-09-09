/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:46:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 15:41:04 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const & copy)
{
	*this = copy;
}

Intern::~Intern(void)
{
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return (*this);
}

AForm *Intern::createShrubberyCreationForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string name, std::string const & target)
{
	AForm	*newForm = NULL;
	typedef AForm* (Intern::*formCreators)(std::string const & target);
	std::string forms[3] = { "shrubbery request", "robotomy request", "presidentialpardon request" };
	formCreators list[] = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if ( forms[i] == name )
		{
			newForm = (this->*list[i])(target);
			break;
		}
	}
	if (!newForm)
		throw Intern::FormWrongName();
	std::cout << "Intern creates " << newForm->getName() << std::endl;
	return (newForm);
}

const char * Intern::FormWrongName::what() const throw()
{
	return ("Error: Name not found in the forms options");
}