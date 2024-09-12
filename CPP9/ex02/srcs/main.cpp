/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:41:46 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/12 16:37:12 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"
#include <cstring>

int	main(int ac, char **av)
{

	try
	{
		if (ac <= 2)
			throw PmergeMe::InvalidInputException();
		PmergeMe PmergeMe(ac, av);
		PmergeMe.sort();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
