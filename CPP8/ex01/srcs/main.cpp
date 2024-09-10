/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:21:38 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/10 17:03:24 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main()
{
	std::cout << "42 tests: " << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "Perso tests: " << std::endl;
	try {
		Span sp2 = Span(10000);
		srand(time(NULL));
		std::vector<int> tmp;
		int test;
		for (int i = 0; i < 10000; i++)
		{
			test = rand() % 1000;
			// std::cout << test << std::endl;
			tmp.push_back(test);
		}
		sp2.addRange(tmp);
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}