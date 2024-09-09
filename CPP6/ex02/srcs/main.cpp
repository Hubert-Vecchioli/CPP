/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:40:13 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/09 11:56:01 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>

Base *generate(void)
{
	std::srand(std::time(0));
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "A generated" << std::endl;
			return (new A);
		case 1:
			std::cout << "B generated" << std::endl;
			return (new B);
		case 2:
			std::cout << "C generated" << std::endl;
			return (new C);
		default:
			return (NULL);
	}
}
void	identify(Base &p)
{
	try
	{
		if (dynamic_cast<A*>(&p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B*>(&p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C*>(&p))
			std::cout << "C" << std::endl;
		else
			throw std::exception();
	}
	catch (std::exception &e)
	{
		std::cerr << "Unknown class" << std::endl;
	}
}


void	identify(Base *p)
{
	if (p == NULL)
		std::cout << "NULL" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
	return ;
}

int	main(void)
{
	Base *base;
	base = generate();
	std::cout << "Generated a new random class" << std::endl;
	std::cout << "The random class is: (via a pointer)" << std::endl;
	identify(base);
	std::cout << "The random class is: (via a reference)" << std::endl;
	identify(*base);
	delete base;
	return (0);
}