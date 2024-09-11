/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:08:22 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/11 01:46:59 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src)
{
}

template<typename T>
MutantStack<T>::~MutantStack(void) 
{
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &src)
{
	if (this != &src)
		std::stack<T>::operator=(src);
	return (*this);
}

#endif
