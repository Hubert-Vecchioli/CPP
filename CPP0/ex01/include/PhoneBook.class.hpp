/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:53:36 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/21 02:07:37 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"
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