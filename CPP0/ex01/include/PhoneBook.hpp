/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:53:36 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 11:04:18 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <limits>

class PhoneBook {
	private:
		Contact		contact_[8];
		int			id_;
	public: 
		PhoneBook(void);
		~PhoneBook(void);
		void	ft_add_contact(void);
		void	ft_list_contacts(void) const;
		void	ft_search_contact(void) const;
};

#endif