/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:46:42 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 15:11:50 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <algorithm>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & copy);
		~Intern(void);

		Intern & operator=(Intern const & rhs);

		AForm * makeForm(std::string name, std::string const & target);
		AForm *createShrubberyCreationForm(std::string const & target);
		AForm *createRobotomyRequestForm(std::string const & target);
		AForm *createPresidentialPardonForm(std::string const & target);

		class FormWrongName : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif