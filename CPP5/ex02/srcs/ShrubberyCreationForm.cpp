/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:57:12 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 14:36:13 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), target_("Unkown")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreationForm", 145, 137), target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : AForm(copy), target_(copy.target_)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	(void)rhs;
	return (*this);
}

void ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream	file;
	std::string		filename = this->target_ + "_shrubbery";

	file.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!file.is_open())
		throw FileOpenFailureException();
	file << "   /\\\n  /**\\\n /****\\\n   ||\n   ||\n\n   /\\\n  /**\\\n /****\\\n   ||\n   ||\n" << std::endl;
	file.close();
}

const char* ShrubberyCreationForm::FileOpenFailureException::what() const throw()
{
	return ("cannot open file");
}