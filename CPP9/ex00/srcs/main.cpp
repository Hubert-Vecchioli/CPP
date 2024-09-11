/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:39:20 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/11 15:41:33 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
		{
			throw BitcoinExchange::WrongInputException();
			//return (1); needed ??
		}
		BitcoinExchange	portfolio(av[1]);
		
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

    return (0);
}