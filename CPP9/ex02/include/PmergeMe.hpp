/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:42:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/12 17:07:55 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>

class PmergeMe
{
	private:
		std::list<int> listData_;
		std::vector<int> vectorData_;
		PmergeMe(void);
		void printData_(void) const;
	public:
		PmergeMe(int ac, char **av);
		PmergeMe(PmergeMe const &rhs);
		~PmergeMe(void);
		PmergeMe &operator=(PmergeMe const &rhs);
		void sort(void);
		
	class InvalidInputException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif