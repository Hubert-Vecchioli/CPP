/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:41:55 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/13 02:39:13 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "utils.cpp"

PmergeMe::PmergeMe( void )
{
}

PmergeMe::PmergeMe(int ac, char **av): duration_list_(0), duration_vector_(0)
{
	if (ac ==2)
	{
		std::string next_number;
    	std::stringstream ss(av[1]);
		while (std::getline(ss, next_number, ' '))
		{
			std::clock_t start_list = std::clock();
			listData_.push_back(convertInt_(next_number));
			std::clock_t end_list = std::clock();
			this->duration_list_ =+ 1000.0 * (end_list - start_list) / CLOCKS_PER_SEC;

			std::clock_t start_vector = std::clock();
			vectorData_.push_back(convertInt_(next_number));
			std::clock_t end_vector = std::clock();
			this->duration_vector_ =+ 1000.0 * (end_vector - start_vector) / CLOCKS_PER_SEC;			
		}
		return ;
	}
	for(int i = 1; i < ac; i++)
	{
		std::clock_t start_list = std::clock();
		listData_.push_back(convertInt_(av[i]));
		std::clock_t end_list = std::clock();
		this->duration_list_ =+ 1000.0 * (end_list - start_list) / CLOCKS_PER_SEC;

		std::clock_t start_vector = std::clock();
		vectorData_.push_back(convertInt_(av[i]));
		std::clock_t end_vector = std::clock();
		this->duration_vector_ =+ 1000.0 * (end_vector - start_vector) / CLOCKS_PER_SEC;		
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
	std::cout << "Before : ";
	iter(this->listData_, 5, print_info<int>);
	std::cout << std::endl;

	std::clock_t start_list = std::clock();
	mergeInsertionSort(listData_);
	std::clock_t end_list = std::clock();
	this->duration_list_ =+ 1000.0 * (end_list - start_list) / CLOCKS_PER_SEC; // Temps en microsecondes
	
	std::cout << "After : ";
	iter(this->listData_, 5, print_info<int>);
	std::cout << std::endl;

	std::clock_t start_vector = std::clock();
	mergeInsertionSort(vectorData_); 
	std::clock_t end_vector = std::clock();
	this->duration_vector_ =+ 1000.0 * (end_vector - start_vector) / CLOCKS_PER_SEC; // Temps en microsecondes

	std::cout << "Time to process a range of " << listData_.size() << " elements with std::list: " << this->duration_list_ << " ms" << std::endl;
	std::cout << "Time to process a range of " << vectorData_.size() << " elements with std::vector: " << this->duration_vector_ << " ms" << std::endl;
}

int PmergeMe::convertInt_(const std::string &input)
{
	std::stringstream ss(input);
    int result;
    ss >> result;
    if (ss.fail())
        throw std::runtime_error("Invalid input");
	if (result < 0)
		throw InvalidInputException();
    return result;
}

const char* PmergeMe::InvalidInputException::what() const throw()
{
	return ("Error");
}
