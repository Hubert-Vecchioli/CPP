/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:07:28 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 08:41:07 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define NB_ANIMALS 4

int main()
{
	{
	Animal *animals[NB_ANIMALS];

	for (int i = 0; i < NB_ANIMALS; i++)
	{
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();

		animals[i]->makeSound();
		animals[i]->getBrain()->setIdea(0, "Who am I?");
		animals[i]->getBrain()->setIdea(1, "I should buy a boat..");
		std::cout << "Idea: " << animals[i]->getBrain()->getIdeas()[0] << std::endl;
		std::cout << "Idea: " << animals[i]->getBrain()->getIdeas()[1] << std::endl << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < NB_ANIMALS; i++)
		delete animals[i];
	return (0);
	}
	return 0;
}