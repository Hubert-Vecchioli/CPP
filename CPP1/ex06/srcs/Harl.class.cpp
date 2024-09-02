/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:45:38 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/26 15:20:45 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"

	Harl::Harl(void)
	{
	}
	
	Harl::~Harl(void)
	{
	}
	
	void Harl::debug_( void )
	{
		std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n" << std::endl;
	}
	
	void Harl::info_( void )
	{
		std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n" << std::endl;
	}

	void Harl::warning_( void )
	{
		std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
	}

	void Harl::error_( void )
	{
		std::cout << "[ ERROR ]\nThis is unacceptable ! I want to speak to the manager now.\n" << std::endl;
	}

	void Harl::complain( std::string level )
	{
		std::string complain_level[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
		int index = -1;
		
		for (int i = 0; i < 4; i++)
		{
			if ( complain_level[i] == level )
			{
				index = i;
				break ;
			}
		}
		switch(index)
		{
		case 0:
			this->debug_();
		case 1:
			this->info_();
		case 2:
			this->warning_();
		case 3:
			this->error_();
			break ;
		default:
			std::cout << "Invalid level input, please retry" << std::endl;
			std::cout << "Available options are DEBUG, INFO, WARNING and ERROR" << std::endl;
		}
	}
