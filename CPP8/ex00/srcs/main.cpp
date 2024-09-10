/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:46:07 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/10 17:03:17 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"
#include <iostream>
#include <bits/stdc++.h>

int	main(void)
{
	std::set<int> vec;
	
	for (int i = 0; i < 10; i++)
		vec.insert(i);
	
	std::cout << "Test good value: " << std::endl;
	try
	{
		easyfind(vec, 5);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}
	try
	{
		easyfind(vec, 19);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}
	return (0);
}