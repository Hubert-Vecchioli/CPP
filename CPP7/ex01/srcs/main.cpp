/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:52:19 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/10 12:22:55 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Templates_fct.hpp"

int main(void)
{
	int foo [5] = { 16, 2, 77, 40, 12071 };
	char str[] = "abcde";
	
	std::cout << "Original list: " << std::endl;
	iter<char>(str, 5, print_info<char>);
	iter<int>(foo, 5, print_info<int>);
	std::cout << "New list: " << std::endl;
	iter<char>(str, 5, addOne<char>);
	iter<int>(foo, 5, addOne<int>);
	iter<char>(str, 5, print_info<char>);
	iter<int>(foo, 5, print_info<int>);

}