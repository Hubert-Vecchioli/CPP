/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:53:45 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 11:48:51 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"


int	main(void)
{
	PhoneBook	phoneBook;
	std::string	phone_book_command;
	
	std::cout << "Welcome to your awesome phonebook." << std::endl;
	std::cout << "Would you like to ADD or SEARCH for a contact? Else you can EXIT." << std::endl;
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, phone_book_command);
		if (std::cin.eof())
		{
			break;
		}
		if (phone_book_command == "ADD")
			phoneBook.ft_add_contact();
		else if (phone_book_command == "SEARCH")
			phoneBook.ft_search_contact();
		else if (phone_book_command == "EXIT")
			break ;
		if (!std::cin.eof())
			std::cout << "Would you like to ADD or SEARCH for a contact? Else you can EXIT." << std::endl;
	}
	std::cout << "You are exiting - See you soon!" << std::endl;
	return (0);
}
