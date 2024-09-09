/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:53:31 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 11:49:59 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const name_;
		bool isSigned_;
		const int gradeToSign_;
		const int gradeToExecute_;
		AForm(void);
	public:
		AForm(const std::string & name, int gradeToSign);
		AForm(const std::string & name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &src);
		~AForm();
		AForm & operator=(AForm const &src);

		std::string const getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getgradeToExecute(void) const;
		void beSigned(Bureaucrat const & Bureaucrat);
		virtual void beExecuted(void) const = 0;
		void executeForm(const Bureaucrat & executor) const;

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
		class NotYetSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif