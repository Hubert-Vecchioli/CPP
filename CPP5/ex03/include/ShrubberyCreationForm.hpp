/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:11:56 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/06 14:36:35 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const	target_;
		ShrubberyCreationForm(void);

	public:
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & copy);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

		void beExecuted(void) const;

		class FileOpenFailureException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif