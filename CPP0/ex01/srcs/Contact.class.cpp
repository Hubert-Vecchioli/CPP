/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:53:26 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/21 02:06:49 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string Contact::getInput_(std::string str) const
{
	std::string input;

	std::cout << str << std::endl;
	std::getline(std::cin, input);
	while (input.empty() || !std::cin.good())
	{
		std::cin.clear();
		std::cout << "Invalid input" << std::endl;
		std::cout << str << std::endl;
		std::cin >> input;
		if (!input.empty() && std::cin.good())
		{
			break;
		}
	}
	return (input);
}

std::string Contact::getLimitedDisplay_(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::ft_create_contact(void)
{
	this->firstName_ = this->getInput_("Please enter the first name: ");
	this->lastName_ = this->getInput_("Please enter the last name: ");
	this->nickName_ = this->getInput_("Please enter the nickname: ");
	this->phoneNumber_ = this->getInput_("Please enter the phone number: ");
	this->darkestSecret_ = this->getInput_("Please enter the darkest secret: ");
}

void	Contact::ft_display_to_search(int i) const
{
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|" << std::setw(10) << i;
	std::cout << "|" << std::setw(10) << this->getLimitedDisplay_(this->firstName_);
	std::cout << "|" << std::setw(10) << this->getLimitedDisplay_(this->lastName_);
	std::cout << "|" << std::setw(10) << this->getLimitedDisplay_(this->nickName_);
	std::cout << "|"<< std::endl;
}

void	Contact::ft_display(void) const
{
	std::cout << "First name: " << this->firstName_ << std::endl;
	std::cout << "Last name: " << this->lastName_ << std::endl;
	std::cout << "Nick name: " << this->nickName_ << std::endl;
	std::cout << "Phone number: " << this->phoneNumber_ << std::endl;
	std::cout << "Darkest secret: " << this->nickName_ << std::endl;
}

int	Contact::ft_is_empty(void) const
{
	if (this->firstName_.empty() 
		|| this->lastName_.empty() 
		|| this->nickName_.empty() 
		|| this->phoneNumber_.empty() 
		|| this->darkestSecret_.empty())
		return (1);
	return (0);
}
