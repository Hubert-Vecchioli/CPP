/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:53:31 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 08:38:05 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const name_;
		bool isSigned_;
		const int gradeToSign_;
		const int gradeToExecute_;
		Form(void);
	public:
		Form(const std::string & name, int gradeToSign);
		Form(const std::string & name, int gradeToSign, int gradeToExecute);
		Form(Form const &src);
		~Form();
		Form & operator=(Form const &src);
		std::string const getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getgradeToExecute(void) const;
		void beSigned(Bureaucrat const & Bureaucrat);

		
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
		
		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif