/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:53:29 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 11:04:15 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <limits>
# include <string>
# include <cstdlib>

class Contact {
	private:
		std::string	firstName_;
		std::string	lastName_;
		std::string	nickName_;
		std::string	phoneNumber_;
		std::string darkestSecret_;
		std::string	getInput_(std::string str) const;
		std::string	getLimitedDisplay_(std::string str) const;
	public:
		Contact(void);
		~Contact(void);
		void	ft_create_contact(void);
		void	ft_display_to_search(int i) const;
		void	ft_display(void) const;
		int		ft_is_empty(void) const;

};

#endif