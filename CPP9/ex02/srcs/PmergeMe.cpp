/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:41:55 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/12 17:05:05 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "utils.cpp"
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>

PmergeMe::PmergeMe( void )
{
}

PmergeMe::PmergeMe(int ac, char **av)
{
	for(int i = 0; i < ac; i++)
	{
		listData_.push_back(atoi(av[i]));
		vectorData_.push_back(atoi(av[i]));
	}
}

PmergeMe::PmergeMe(PmergeMe const &rhs)
{
	*this = rhs;
	return ;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		this->listData_ = rhs.listData_;
		this->vectorData_ = rhs.vectorData_;
	}
	return (*this);
}

void PmergeMe::sort( void )
{
	// Print the list
	

	std::clock_t start_list = std::clock();
	mergeInsertionSort(listData_); // Tri direct de la liste
	std::clock_t end_list = std::clock();
	double duration_list = 1000000.0 * (end_list - start_list) / CLOCKS_PER_SEC; // Temps en microsecondes

	// Mesurer le temps pour std::vector
	std::clock_t start_vector = std::clock();
	mergeInsertionSort(vectorData_); // Utilisation de std::sort pour vector
	std::clock_t end_vector = std::clock();
	double duration_vector = 1000000.0 * (end_vector - start_vector) / CLOCKS_PER_SEC; // Temps en microsecondes

	// Affichage du temps pris pour chaque tri
	std::cout << "Time to process a range of " << listData_.size() << " elements with std::list: " << duration_list << " us" << std::endl;
	std::cout << "Time to process a range of " << vectorData_.size() << " elements with std::vector: " << duration_vector << " us" << std::endl;
}

const char* PmergeMe::InvalidInputException::what() const throw()
{
	return ("Error: Invalid input.");
}