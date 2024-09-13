/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:41:46 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/13 01:55:45 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//arg=$(shuf -i 1-100000 -n 3000 | tr "\n" " "); ./PmergeMe $arg
#include "PmergeMe.hpp"

int	main(int ac, char **av)
{

	try
	{
		if (ac < 2)
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
