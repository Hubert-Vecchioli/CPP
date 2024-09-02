/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:07:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/02 13:56:38 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
	{
		std::cout << "Please enter a single input" << std::endl;
		exit(0);
	}
	harl.complain(av[1]);
}