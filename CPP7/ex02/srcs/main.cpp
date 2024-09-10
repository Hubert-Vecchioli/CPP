/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:55:44 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/10 15:01:38 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"

int main (void)
{
	int c1;
	Array<char> arr1(10);
	Array<int> arr2(20);
	Array<int>arr3(1);

	c1 = 97;
	for(unsigned int i = 0; i < arr1.size(); i++)
		arr1[i] = c1++;
	std::cout << "Char test: " << std::endl;
	for(unsigned int i = 0; i < arr1.size(); i++)
		std::cout << arr1[i] << ", ";
	std::cout << std::endl << std::endl;

	std::cout << "Int test: " << std::endl;
	c1 = 97;
	for(unsigned int i = 0; i < arr2.size(); i++)
		arr2[i] = c1++;
	for(unsigned int i = 0; i < arr2.size(); i++)
		std::cout << arr2[i] << ", ";
	std::cout << std::endl << std::endl;

	std::cout << "Exception test: " << std::endl;
	try
	{
		std::cout << "Access to element [0]: " << arr2[0] << std::endl;
		std::cout << "Access to element [100]: " << arr2[100] << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Copy test: " << std::endl;
	arr3 = arr2;
	std::cout << "- New arr3, copied from arr2 : " << std::endl;

	for(unsigned int i = 0; i < arr2.size(); i++)
		arr2[i] -= 96;
	for(unsigned int i = 0; i < arr3.size(); i++)
		std::cout << arr3[i] << ", ";
	std::cout << std::endl;

	std::cout << "- Modifed arr2 : " << std::endl;
	for(unsigned int i = 0; i < arr2.size(); i++)
		std::cout << arr2[i] << ", ";
	std::cout << std::endl << std::endl;

	return (0);
}
