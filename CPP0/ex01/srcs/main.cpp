/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:53:45 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/19 01:06:30 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.class.hpp"


int	main(void)
{
	PhoneBook	phoneBook;
	std::string	phone_book_command;
	
	std::cout << "Welcome to your awesome phonebook." << std::endl;
	std::cout << "Would you like to ADD or SEARCH for a contact? Else you can EXIT." << std::endl;
	std::cout << "> " << std::flush;	
	while (true)
	{
		if (!phone_book_command.empty() || phone_book_command == "\n")
		{
			std::cout << "Would you like to ADD or SEARCH for a contact? Else you can EXIT." << std::endl;
			std::cout << "> " << std::flush;	
		}
		else if (std::cin.eof())
		{
			break;
		}
		std::getline(std::cin, phone_book_command);
		if (phone_book_command == "ADD")
			phoneBook.ft_add_contact();
		else if (phone_book_command == "SEARCH")
			phoneBook.ft_search_contact();			
		else if (phone_book_command == "EXIT")
			break ;
	}
	std::cout << "You are exiting - See you soon!" << std::endl;
	return (0);
}
