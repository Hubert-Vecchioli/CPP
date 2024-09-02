/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:45:38 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 13:56:29 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

	Harl::Harl(void)
	{
	}
	
	Harl::~Harl(void)
	{
	}
	
	void Harl::debug_( void )
	{
		std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
	}
	
	void Harl::info_( void )
	{
		std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
	}

	void Harl::warning_( void )
	{
		std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	}

	void Harl::error_( void )
	{
		std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
	}

	void Harl::complain( std::string level )
	{
		typedef void (Harl::*complain_fct)(void);
		std::string complain_level[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
		complain_fct list[] = { &Harl::debug_, &Harl::info_, &Harl::warning_, &Harl::error_ };

		for (int i = 0; i < 4; i++)
		{
			if ( complain_level[i] == level )
			{
				(this->*list[i])();
				return ;
			}
		}
		std::cout << "Invalid level input, please retry" << std::endl;
		std::cout << "Available options are DEBUG, INFO, WARNING and ERROR" << std::endl;
	}
