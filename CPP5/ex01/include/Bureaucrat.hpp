/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:53:31 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 08:36:07 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150
class Form;

class Bureaucrat
{
	private:
		std::string const name_;
		int grade_;
		Bureaucrat(void);
	public:
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const &src);
		std::string const getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(Form & form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif