/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:18:07 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/22 15:07:20 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR;
	std::string &stringREF = str;
	stringPTR = &str;

	std::cout << "L’adresse de la string en mémoire: " << &str << std::endl;
	std::cout << "L’adresse stockée dans stringPTR: " << stringPTR << std::endl;
	std::cout << "L’adresse stockée dans stringREF: " << &stringREF << std::endl;

	std::cout << "La valeur de la string: " << str << std::endl;
	std::cout << "La valeur pointée par stringPTR: " << *stringPTR << std::endl;
	std::cout << "La valeur pointée par stringREF: " << stringREF << std::endl;

	return (0);
}