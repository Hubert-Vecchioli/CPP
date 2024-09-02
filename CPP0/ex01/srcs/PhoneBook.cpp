/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:53:34 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 12:02:38 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : id_(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::ft_add_contact(void)
{
	if (this->id_ == 8)
		this->id_ = 0;
	this->contact_[this->id_].ft_create_contact();
	this->id_++;
}

void	PhoneBook::ft_list_contacts(void) const
{
	std::cout << "|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|" << std::endl;
	std::cout << "|    ID    |FIRST_NAME| LAST_NAME| NICKNAME |" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->contact_[i].ft_is_empty())
			continue;
		this->contact_[i].ft_display_to_search(i);
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}


void	PhoneBook::ft_search_contact(void) const
{	
	int	input;

	this->ft_list_contacts();
	std::cout << std::endl;
	std::cout << "Please enter the contact id to display" << std::endl;
	std::cin >> input;
	if (std::cin.good() && !this->contact_[input].ft_is_empty() && input >= 0 && input <= 7)
	{
		std::cout << "You request the contact id #";
		std::cout << input << std::endl;
		this->contact_[input].ft_display();	
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	else if (std::cin.eof())
	{
		return ;
	}
	else
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input - Aborting SEARCH." << std::endl;
		return ;
	}
}
