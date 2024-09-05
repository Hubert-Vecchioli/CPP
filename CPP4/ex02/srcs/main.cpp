/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:07:28 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/05 12:17:47 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define NB_ANIMALS 4

int main()
{
	{
		AAnimal *animals[NB_ANIMALS];

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
		std::cout << std::endl;
	}
	{
		Dog test = Dog();

		test.makeSound();
		test.getBrain()->setIdea(0, "Am I alive?");
		test.getBrain()->setIdea(1, "I should definitly buy a boat..");
		std::cout << "Idea: " << test.getBrain()->getIdeas()[0] << std::endl;
		std::cout << "Idea: " << test.getBrain()->getIdeas()[1] << std::endl << std::endl;
		Dog copy_test = Dog(test);
		std::cout << "Idea: " << copy_test.getBrain()->getIdeas()[0] << std::endl;
		std::cout << "Idea: " << copy_test.getBrain()->getIdeas()[1] << std::endl << std::endl;
	}
	// {
	// 	AAnimal	ghost = AAnimal();
	// 	ghost.makeSound();
	// }
	return (0);
}