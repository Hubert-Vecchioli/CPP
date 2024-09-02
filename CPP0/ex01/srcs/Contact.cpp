/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:53:26 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 11:10:44 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
		if (std::cin.eof())
		{
			break;
		}
		std::cin.clear();
		input.clear();
		std::cout << "Invalid input" << std::endl;
		std::cout << str << std::endl;
		std::getline(std::cin, input);
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
	if (this->firstName_.empty())
		return ;
	this->lastName_ = this->getInput_("Please enter the last name: ");
	if (this->lastName_.empty())
		return ;
	this->nickName_ = this->getInput_("Please enter the nickname: ");
	if (this->nickName_.empty())
		return ;
	this->phoneNumber_ = this->getInput_("Please enter the phone number: ");
	if (this->phoneNumber_.empty())
		return ;
	this->darkestSecret_ = this->getInput_("Please enter the darkest secret: ");
	if (this->darkestSecret_.empty())
		return ;
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
